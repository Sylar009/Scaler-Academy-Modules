public class App {
    public static void main(String[] args) {
        StudentRegistry registry  = new StudentRegistry();
        fillRegistry(registry);

        Student copy = registry.get("wed_13_sept").clone();

        Student isCopy = registry.get("wed_13_sept_is").clone();

        System.out.println(copy);

        System.out.println(copy == isCopy ? "Is a Copy" : "Not A Copy" );

    }

    private static void fillRegistry(StudentRegistry registry) {
        Student original  = new Student();
        original.setBatch("august");
        original.setAverageBatchPsp(70);

        /// filling the registy
        registry.register("wed_13_sept", original);


        IntelligentStudent is = new IntelligentStudent();
        is.setBatch("august");
        is.setAverageBatchPsp(70);

        registry.register("wed_13_sept_is", is);

    }
}
