public class App {
    @SuppressWarnings("static-access")
    public static void main(String[] args) throws Exception {

    Student s = Student.getBuilder()
        .setName("Sanyam")
        .setAge(10)
        .setEmail("sanyam@gmail.com").setNestedStudent(new NestedStudent()).build();
        

    System.out.println("Student Data :: " + s.getBuilder().getName() );
    
    }
}
