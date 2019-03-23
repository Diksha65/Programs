public static List<Apple> filterGreenApples(List<Apple> inventory) {
    List<Apple> result = new ArrayList<>();
    for(Apple apple: inventory) {
        if("green".equals(apple.getColor()))
            result.add(apple);
    }
    return result;
}

public static List<Apple> filterApplesByColor(List<Apple> inventory, String color) {
    List<Apple> result = new ArrayList<>();
    for(Apple apple: inventory) {
        if(apple.getColor().equals(color))
            result.add(apple);
    }
    return result;
}

List<Apple> greenApples = filterApplesByColor(inventory, "green");
List<Apple> redApples = filterApplesByColor(inventory, "red");


public static List<Apple> filterApplesByWeight(List<Apple> inventory, int weight) {
    List<Apple> result = new ArrayList<>();
    for(Apple apple: inventory) {
        if(apple.getWeight() > weight)
            result.add(apple);
    }
    return result;
}

public static List<Apple> filterApples(List<Apple> inventory, int weight, String color, boolean flag) {
    List<Apple> result = new ArrayList<>();
    for(Apple apple: inventory) {
        if(flag && apple.getColor().equals(color) || (!flag && apple.getWeight() > weight))
            result.add(apple);
    }
    return result;
}


public interface ApplePredicate {
    boolean test(Apple apple);
}

public class AppleHeavyWeightPredicate implements ApplePredicate {
    public boolean test(Apple apple) {
        return apple.getWeight() > 150;
    }
}

public class AppleGreenColorPredicate implements ApplePredicate {
    public boolean test(Apple apple) {
        return "green".equals(apple.getColor());
    }
}

public class AppleRedAndHeavyPredicate implements ApplePredicate {
    public boolean test(Apple apple) {
        return "red".equals(apple.getCOlor()) 
                    && apple.getWeight() > 150;
    }
}

public static List<Apple> filter(List<Apple> inventory, ApplePredicate p) {
    List<Apple> result = new ArrayList<>();
    for(Apple apple: inventory) {
        if(p.test(apple))
            result.add(apple);
    }
    return result;
}

List<Apple> redAndHeavyApple = filter(inventory, new AppleRedAndHeavyPredicate());


public static void PrettyPrintApple(List<Apple> inventory, AppleFormatter p) {
    for(Apple apple : inventory) {
        String output = p.accept(apple);
        System.out.println(output);
    }
}

public interface AppleFormatter {
    String accept(Apple apple);
}

public class AppleFancyFormatter implements AppleFormatter {
    public String accept(Apple apple) {
        return "An apple of" + apple.getWeight() + "g.";
    }
}

PrettyPrintApple(inventory,new AppleFancyFormatter());

List<Apple> redApples = filterApples(inventory, new ApplePredicate() {
    public boolean test(Apple apple) {
        return "red".equals(apple.getColor());
    }
});

List<Apple> result = filterApples(inventory, (Apple, apple) -> "red".equals(apple.getColor()));

Behaviour parameterization - 
1.anonymous class
2.lambdas
3.classes

public interface Predicate<T> {
    boolean test(T);
}

public static<T> List<T> filter(List<T> list, Predicate<T. p) {
    List<T> result = new ArrayList<>();
    for(T e:list) {
        if(p.test(e))
            result.add(e)
    }
    return result
}

List<Apple> redApples = filter(inventory, (Apple apple) -> "red".equals(apple.getColor()));

List<String> evenNos = filter(numbers, (Integer, i) -> i%2==0)

public interface Comparator<T> {
    public int comapre(T a, T b);
}

inventory.sort(new Comparator<Apple>() {
    public int compare(Apple a, Apple b) {
        return a.getWeight().compareTo(b.getWeight())
    }
})

inventory.sort((Apple a, Apple b) -> a.getWeight().compareTo(b.getWeight()));

public interface Runnable {
    public void run()
}

Thread t = new Thread(new Runnable() {
    public void run() {
        System.out.println("Hi");
    }
});

Thread t = new Thread(() -> System.out.println("Hi"));

Button button = new Button("Send")
button.setOnAction(new EventHandler<ActionAHndler>() {
    public void handle(ActionEvent a) {
        label.setText("Sent!")
    }
});

button.setOnAction((ActionEvent a) -> labe;.setText("Sent!"))

/*
lambdas are 
anonymous functions as have no name
function as have parameters, body, return type, and exceptions
passed aaround as can be used as a parameter for another function
concise

Comparator<Apple> wt = (Apple a, Apple b) -> a.getWeight().compareTo(b.getWeight())

(parameter) -> expression
(parameters) -> {statements;}

functional interfce specifies only one abstract method but can sepcify many default methods
*/

Runnable r1 = () -> System.out.println("Hi");

Runnable r2 = new Runnable() {
    public void run() {
        System.out.println("Hi");
    }
}

public static void process(Runnable r) {
    r.run();
}

this abstract method is called function descriptor

public void process(Runnable r) {
    r.run();
}

process(() -> System.out.printl("Hi"));

public static Stirng processFile() throwsIOException {
    try {
        (BufferedReader br = new BufferedReader(new FileReader("data.txt"))) {
            return br.readLine();
        }
    }
}

String result = processFile((BufferedReader br) -> br.readLine() + br.readLine())

public interface BRP {
    String process(BufferedReader b) throws IOException;
}

public static String processFile(BRP p) throws IOException {
    try(bufferedReader br = new BufferedReader(new FileReader("data.txt"))) {
        return p.process(br);
    }
}

String oneLine = processFile((BufferedReader br) -> br.readLine());
String twoLines = processFile((BufferedReader br) -> br.readLine() + br.readLine());


@FunctionalInterface
public interface Predicate<T> {
    boolean test(T t);
}

public static<T> List<T> filter(List<T> list, Predicate <T> p) {
    List<T>  result = new ArrayList()<>
    for(T t : list) 
        if(p.test(t))
            result.add(t)
    return result
}

Predicate<String> nonEmptyStringPredicate = (String s) -> !s.isEmpty();
List<String> nonEmpty =  filter(listOfThings, nonEmptyStringPredicate)

@FunctionalInterface
public interface Consumer<T>{
    void accept(T t);
}

public static<T> void forEach(List<T> list, Consumer<T> c) {
    for(T i: list) 
        c.accept(i);
}

forEach(Arrays.asList(1,2,3,4,5), (Integer i) -> System.out.println(i))

@FileReader
public interfae Function<T,R> {
    R.apply(T t);
}

public static <T,R> List<R> map(List<T> list, Function<T,R> f) {
    List<R> result = new Arraylist()
    for(T s: list)
        result.add(f.apply(s))
    return result
}

List<Intege> l = map(Array.asList("lambdas","in","action"), (String s) -> s.length());

Function<BufferedReader, String> f = (BufferedReader b) {
    try {
        return br.readLine();
    } 
    catch(IOException e) {
        throw new RuntimeException(e);
    }
};

Comaprator<Apple> c = (Apple a, Apple b) -> a.getWeight().compareTo(b.getWeight())
Comparator<Apple> c = (a,b) -> a.getWeight().compareTo(b.getWeight())

Instance variables are stored on heap and local varianles are stored on stack

inventory.sort(comparing(Apple::getWeight()));

List<String> str = Arrays.asList("a","B","A","b");
str.sort((s1,s2) -> s1.compareToIgnoreCase(s2));
str.sort(String::compareToIgnoreCase);

Function<String, Integer> stringToInteger = Integer::parseInt;

Supplier<Apple> c2 = Apple::new
Apple a1 = c2.get()

Supplier<Apple> c2 = ()->new Apple();
Apple a1 = c2.get()

List<Integer> wt = Arrays.asList(7,3,4,10);
List<Apple> apples = map(wt, Apple::new);

public static List<Apple> map(List<Integer> list, Function<Integer, Apple> f) {
    List<Apple> result = new ArrayList<>();
    for(Integer i : list)
        result.add(f.apply(i))
    return result;
}

BiFunction<String, Integer, Apple> c3 = Apple::new;
Apple c3 = c3.apply("gree", 10);

static Map<String, Function<Integer, Fruit>> map = new HashMap<>();
static {
    map.put("apple", Apple::new);
    map.put("orange", Orange::new);
}

public static Fruit giveMeFruit(String fruit, Integer weight) {
    return map.get(fruit.toLowerCase()).apply(weight);
}


public Interfaec TriFunction<T,U,V,R>{
    R apply(T t, U u, V v);
}

void sort(Comparator<?super E> c)

//--Pass code--
public class AppleComparator implements Comaparator<Apple> {
    public int compare(Apple a1, APple a2) {
        return a1.getWeight().compareTo(a2.getWeight());
    }
}
inventory.sort(new AppleComparator());
//--

//--Anonymous class--
inventory.sort(new Comparator<Apple>() {
    public int compare(Apple a1, APple a2) {
        return a1.getWeight().compareTo(a2.getWeight());
    }
});
//--

//--Lambda expression--
inventory.sort((Apple a1, Apple a2) 
        -> a1.getWeight().compareTo(a2.getWeight())

inventory.sort((a1,a2) -> a1.getWeight().compareTo(a2.getWeight())
//--

Comparator<Apple> c = Comparator.comparing((Apple a) -> a.getWeight());

import static java.util.Comparator.comparing;
inventory.sort(comparing((a) -> a.getWeight()));

//--method references--
inventory.sort(comparing(Apple::getWeight));
//--

inventory.sort(comparing(Apple::getWeight)
                .reversed()
                .thenComparing(Apple::getCountry));

Predicate<Apple> notRedApple = refApple.negate();

Predicate<Apple> a = redApple.and(a->a,getWeight()>150);

Function<Integer, Integer> f = x->x+1;
Function<Integer, Integer> g = x->x*2;
Function<Integer, Integer> h = f.andThen(g);
int result = h.apply(1);

//Predicate
@FunctionalInterface
public interface Predicate<T> {
    boolean test(T t);
}

public static <T> List<T> filter(List<T> list, Predicate<T> p) {
    List<T> results = new ArrayList<>();
    for(T s : list) {
        if(p.test(s))
            results.add(s)
    }
    return results;
}

Predicate<String> nest = (String s) -> !s.isEmpty();
List<String> result = filter(listofstring, nest)

//Consumer
public interface Consumer<T> {
    boid ccept(T t);
}


public sttaic <T> void forEach(list<T> list, consumer<T> c) {
    for(T i : list)
        c.accept(i);
}

forEach(Arrays.asList(1,2,3,4,5), (Integer i) -> SOP(i))

//Function
public interface Function<T> {
    R apply(T t);
}

public static<T,R> List<R> map(List<T> list, Function<T> f) {
    List<R> result = new ArrayList();
    for(T i : list) {
        result.add(f.apply(i))
    }
    return result
}

List<Integer> l = map(Arrays.asList("lambdas","functions"), (String s) -> s.length())

//constructor references
Supplier<Apple> c1 = () - >new Appple();
Apple a1 = c1.get();
//OR
Supplier<Apple> c1 = Apple::new;
Apple a1 = c1.get();

Function<Integer, Apple> c2 = Apple::new;
Apple a2 = c2.apply(110)

Function<Integer, Apple> c2 = (wt) -> new Apple(wt);
Apple a2 = c2.apply(110)


List<Integer> weights = Array.asList(1,2,3,4)
List<Apple> apples = map(weights, Apple::new) 
public static List<Apple> map(List<Integer> list, Function<Integer, Apple> f) {

}


//SORTING
//Pass code
public class AppleComparator implements Comaparator<Apple> {
    public int compare(Apple a1, Apple a2) {
        return a1.getWeight().compareTo(a2.getWeight());
    }
}
inventory.sort(new AppleComparator())

//Anonymous Class
inventory.sort(new Comparator<Apple> {
    public int compare(Apple a1, Apple a2) {
        return a1.getWeight().compareTo(a2.getWeight());
    }
})

//Lambda Expression
inventory.sort((Apple a1, Apple a2) -> a1.getWeight().compareTo(a2.getWeight())
inventory.sort((a1, a2) -> a1.getWeight().compareTo(a2.getWeight())

Comparator<Apple> c = Comparator.comparing((Apple a) -> a.getWeight())
import static java.util.Comparator.comparing
inventory.sort(comparing((a) -> a.getWeight()))

//method references
inventory.sort(comparing(Apple::getWeight))
inventory.sort(comparing(Apple::getWeight).reversed())
inventory.sort(comparing(Apple::getWeight)
                .reversed()
                .thenComparing(Apple::getCountry()))

//composing predicates
Predicate<Apple> notRedApple = redApple.negate()
Predicate<Apple> redAndHeavyApple = redApple.and(a->a.ggetWeight > 150)
Predicate<Apple> redAndHeavyOrGreenApple = redApple.and(a->a.getWeight()>150).or("green".equals(a.getColor()))

//Composing functions
function<Integer, integer> f = x->x+1
function<integer, integer> g = x->x*2
function<integer, integer> h = f.andThen(g)
int result = h.apply(1)

public class Letter {
    public static String addHeader(String text) {
        return "sfsf";
    }
    public static String addFooter(String text) {
        return "gopffof"
    }
    public static String checkSpell(String text) {
        return text.replaceAll("labda", "lambda");
    }
}

Function<String, String> addHeader = Letter::addHeader
Function<String, String> transformation = addHeader.andThen(Letter::checkSpell).andThen(Letter::addFooter);
