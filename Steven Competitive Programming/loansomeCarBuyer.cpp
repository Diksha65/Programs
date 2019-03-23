#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ofstream out; 
ifstream in;


vector<double> createDepRecord(int nor){
    double dep_perc;
    int month_no;
    vector<double> vec(150,0);
    for(int i=0;i<nor;++i){
        in>>month_no>>dep_perc;
        for(int j=month_no; j<vec.size();++j){
            vec[j] = dep_perc;
        }
    }
    return vec;
}

bool satisfiedInZeroMonths(double amnt_loan, double down_payment, double dep_prec){
    double amnt_after_dep = 0;
    if(amnt_loan < down_payment){
        out<<"0 months\n";
        return true;
    }
    amnt_after_dep = (amnt_loan+down_payment) - dep_prec*(amnt_loan+down_payment);
    if(amnt_after_dep > amnt_loan){
        out<<"0 months\n";
        return true;
    }
    return false;
}

void amountOfTimeToBeSatisfied(vector<double> vec, double amnt_after_dep, double down_payment, double amnt_loan){
    double new_loan = amnt_loan;
    for(int i=1;i<vec.size();++i){
        new_loan -= down_payment;
        amnt_after_dep -= vec[i]*amnt_after_dep;
        if(amnt_after_dep > new_loan){
            if(i == 1){
                out<<i<<" month\n";
                return;
            }
            else{
                out<<i<<" months\n";
                return;
            }
        } 
    }
}

int main(){
    double loan_duration, down_payment, amnt_loan;
    int no_dep_rec;
    double amnt_after_dep;
    out.open("output.txt"); in.open("input.txt");
    in>>loan_duration>>down_payment>>amnt_loan>>no_dep_rec;
    
    do{

        vector<double> vec = createDepRecord(no_dep_rec);
        //display(vec);
        if(satisfiedInZeroMonths(amnt_loan, down_payment, vec[0])){
            in>>loan_duration>>down_payment>>amnt_loan>>no_dep_rec;
            continue;
        }

        amnt_after_dep = (amnt_loan+down_payment) - vec[0]*(amnt_loan+down_payment);
        amountOfTimeToBeSatisfied(vec, amnt_after_dep, down_payment, amnt_loan);
        in>>loan_duration>>down_payment>>amnt_loan>>no_dep_rec;

    }while(loan_duration>0);

    out.close(); in.close();
}