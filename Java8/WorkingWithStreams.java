//Java7
List<Dish> lowCaloriesDishes = new ArrayList();
for(Dish d : menu) {
    if(d.getCalories() < 400)
        lowCaloriesDishes.add(d)
}
Collection.sort(lowCaloriesDishes, new Comparator<Dish>() {
    public int comapre(Dish s1, Dish s2) {
        return Integer.compare(s1.getCalories(), s2.getCalories());
    }
})
List<String> lowCaloriesDishNames = new ArrayList();
for(Dish d : lowCaloriesDishes) {
    lowCaloriesDishNames.add(d.getName());
}

//Java8
import static java.util.Comparator.comparing;
import static java.util.stream.Collectors.toList;
List<String> lowCaloriesDihesNames = menu.stream()
                                        .filter(d->d.getCalories < 400)
                                        .sorted(comparing(Dish::getCalories))
                                        .map(Dish::getName)
                                        .collect(toList());
                 
//Dish class
public class Dish {
    private final String name;
    private final boolean vegetarian;
    private final int calories;
    private final Type type;

    public Dish(String name, boolean vegetarian, int calories, Type type) {
        this.name = name;
        this.vegetarian = vegetarian;
        this.calories = calories;
        this.type = type;
    }

    public String getName() { return name; }
    public boolean isVegetarian() { return vegetarian; }
    public int getCalories() { return calories; }
    public Type getType() { return type; }

    @Override
    public String toString() {
        return name;
    }
    public enum Type { MEAT, FISH, OTHER }
}

List<Dish> menu = Arrays.asList {
    newDish("pork", false, 800, Dish.Type.MEAT);
    newDish("beef", false, 700, Dish.Type.MEAT);
    newDish("chicken", false, 400, Dish.Type.MEAT);
    newDish("french fries", true, 530, Dish.Type.OTHER);
    newDish("rice", true, 350, Dish.Type.OTHER);
    newDish("season fruit", true, 120, Dish.Type.OTHER);
    newDish("pizza", true, 550, Dish.Type.OTHER);
    newDish("prawns", false, 300, Dish.Type.FISH);
    newDish("salmon" false, 450, Dish.Type.FISH);
}

import statoc java.util.stream.Collectors.toList;
List<String> threeHighCalorieDishNames = menu.stream()
                                            .filter(d->d.getCalories() >  300)
                                            .map(Dish::getName)
                                            .limit(3)
                                            .collect(toList());
System.out.println(threeHighCalorieDishNames)

List<String> dishnames = menu.stream()
                            .map(Dish::getName)
                            .collect(toList());

List<Integer> dishnameLengths = menu.stream()
                            .map(Dish::getName)
                            .map(String::length)
                            .collect(toList());

List<String> words = Arrays.asList("Java8", "Lambdas", "In", "Action");
List<Integer> wordLengths = words.stream()
                                .map(String::length)
                                .collect(toList());

//get Unique characters from all the words
words.stream().map(word -> word.split("")).distinct().collect(toList());
String[] arrayOfWords = {"Goodbye", "World"}
Stream<String> streamOfWords = Arrays.stream(arrayOfWords);
words.stream().map(word->word.split("")).map(Arrays::stream).distinct().collect(toList());

//flatMap
words.stream().map(w->w.split("")).flatMap(Arrays::stream).distinct().collect(Collectors.toList());

//quiz 5.2
List<Integer> nos1 = Arrays.asList(1,2,3);
List<Integer> nos2 = Arrays.aslIst(3,4);

List<Integer> square = nos1.stream.map(i -> i*i).collect(toList());
List<Int[]> pairs = nos1.stream().flatMap(i -> nos2.stream().map(j-> new int[]{i,j})).collect(toList());

List<Int[]> pairsSumValid = nos1.stream()
                        .flatMap(i -> nos2.stream()
                                            .filter(j -> (i+j)%3==0)
                                            .map(j-> new int[]{i,j}))
                        .collect(toList());

//matches
if(menu.stream.anyMatch(Dish::isVegetarian)) {
    SOPln("Somewhat vegetarian")
}
boolean isHealthy = menu.stream.allMatch(d -> d.getCalories() < 1000)

Optional<Dish> dish = menu.stream()
                            .filter(Dish::isVegetarian)
                            .findAny()
                            .ifPresent(d->SOPln(d.getName()));

Optional<Integer> fist = nos1.stream()
                            .map(x -> x*x)
                            .filter(x -> x%3 == 0)
                            .findFirst();

//reduce
int product = nos1.stream().reduce(0,(a,b) -> a*b);
int sum = nos1.stream().resuce(0,Integer::sum);
Optiona<Integer> sums = nos1.stream.reduce(Integer::sum);
Optinal<Integer> min = nos1.stream().reduce(Integer::min);
Optinal<Integer> max = nos1.stream().reduce(Integer::max);
int min = nos1.stream().reduce((x,y) -> x<y:x?y);

int count = menu.stream().map(d -> 1).reduce(0,(a+b)->a+b);

long count = menu.stream().count() -> to count the number of elements in the stream


//practice
List<Double> ques1 = transactions.stream()
                                .filter(yr -> yr.getYear() == 2011)
                                .sorted(comparing(Transactions::getValue))
                                .collect(toList());

List<String> cities = transactions.stream()
                                .map(t -> t.getTrader().getCity())
                                .distinct()
                                .collect(toList());


List<String> traders = transactions.stream()
                                    .filter(t -> t.getTrader().getCity() == "Cambridge")
                                    .map(t -> t.getTrader())
                                    .sorted(comparing(Transactions::getTrader))
                                    .collect(toList());

String name = transactions.stream()
                            .map(t -> t.getTrader().getName())
                            .distinct()
                            .sorted()
                            .reduce("", (n1,n2) -> n1+n2);

boolean milan = transactions.stream()
                            .anyMatch(t -> t.getTrader().getCity().equals("Milan"));


transactions.stream()
            .filter(t -> t.getTrader().getCity().equals("Cambridge"))
            .map(Transactions::getValue)
            .forEach(System.out.Println)

//gives highest value
Optional<Transaction> ques7 = transactions.stream().map(Transaction::getValue).reduce(Integer::max);
//gives lowest transaction
Optional<Transaction> ques8 = transactions.stream().reduce(t1.getValue() < t2.getValue() ? t1 : t2);


//Primitve stream specializations
int calories = menu.stream().mapToInt(Dish::getCalories).sum()

IntStream intstream = menu.stream().mapToInt(Dish::getCalories)
Stream<Integer> stream = intStream.boxed();

Optionalint maxCalories = menu.stream().mapToInt(Dish::getCalories).max();
int max = maxCalories.orElse(1)

//numeric ranges
IntStream evenNumbers = IntStream.rangeClosed(1,100)
                                .filter(n -> n%2 == 0)
SOPln(evenNumbers.count())

//Pythagorean triples
filter(b->Math.sqrt(a*a + b*b)%1==0)
stream.filter(b->Math.sqrt(a*a+b*b)%1==0).map(b->new int[]{a,b,(int)Math.sqrt(a*a+b*b)})
IntStream.rangeClosed(1,100)
        .filter(b->Math.sqrt(a*a+b*b)%1==0)
        .boxed()
        .map(b->new int[]{a,b,(int)Math.sqrt(a*a+b*b)})
        IntStream.rangeClosed(1,100)
        .filter(b->Math.sqrt(a*a+b*b)%1==0)
        .mapToObj(b->new int[]{a,b,(int)Math.sqrt(a*a+b*b)})
//Final Solution
Stream<int[]> pythagoreanTriples = 
        IntStream.rangeClosed(1,100)
                .boxed()
                .flatMap(a -> IntStream.rangeClosed(a,100)
                                        .filter(b->Math.sqrt(a*a+b*b)%1==0)
                                        .mapToObj(b->new int[]{a,b,(int)Math.sqrt(a*a+b*b)}));
pythagoreanTriples.limit(5).forEach(t->System.out.Println(t[0]+", "+t[1]+", "+t[2]));
//Final optimized solution
Stream<double[]> pythagoreanTriples2 =
        IntStream.rangeClosed(1,100)
                .boxed()
                .flatMap(a -> IntStream.rangeClosed(1,100)
                                        .mapToObj(b->new int[]{a,b,Math.sqrt(a*a+b*b)})
                .filter(t -> t[2]%1==0));

//Streams from values
Stream<String> stream = Stream.of("Java 8", "Lambdas", "In", "Action")
stream.map(String::toUpperCase).forEach(System.out.println);

Stream<String> emptyStream = Stream.empty()

//Stream from arrays
int[] numbers = {2,3,5,7,11}
int sum = Arrays.stream(numbers).sum();

//Streams from files
long uniqueWords = 0;
try(Stream<String> lines = Files.lines(Paths.get("data.txt"), Charset.defaultCharset())) {
    uniqueWords = lines.flatMap(line -> Arrays.stream(line.split(" ")))
                        .distinct()
                        .count();
}
catch(IOException e) {

}

//streams from functions
Stream.iterate(0,n->n+2)
    .limit(10)
    .forEach(System.out::println)

//Fibopnacci Series
Stream.iterate(new int[]{0,1}, t -> new int[]{t[1], t[0]+t[1]})
        .limit(20)
        .forEach(SOPln())

//generate function
IntStream twos = IntStream.geenrate(new IntSupplier() {
    public int getAsInt() {
        return 2;
    }
})

//fibonacci usiing generate
IntSupplier fib = new IntSupplier() {
    private int previous = 0;
    private int current = 1;
    public int getAsInt() {
        int oldPrevious = this.previous;
        int nextValue = this.previous+this.current;
        this.previous = this.current;
        this.current = nextValue;
        return oldPrevious;
    }
};
IntStream.generate(fib).limit(10).forEach(SOPln);