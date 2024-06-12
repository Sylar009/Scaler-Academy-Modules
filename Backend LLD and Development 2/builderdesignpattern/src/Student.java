public class Student {
    String name;
    String email;
    int age;
    String phoneNo;
    double psp;
    private NestedStudent nestedStudent; // nestedclass attribute

    private Student(StudentBuilder h) throws Exception {
        this.age = h.getAge();
        this.email = h.getEmail();
        this.phoneNo = h.getPhoneNo();
        this.name = h.getName();
        this.psp = h.getPsp();
        this.nestedStudent = h.getNestedStudent();
    }

    public static StudentBuilder getBuilder(){
        return new StudentBuilder();
    }

    public static class StudentBuilder{
        private String name;
        private String email;
        private int age;
        private double psp;
        private String phoneNo;
        private NestedStudent nestedStudent;

        // just validating and creating object of student.
        public Student build() throws Exception {
            if(this.getAge() > 100){
                throw new Exception("Age should be less than 100");
            }
            if(this.getPsp() <0){
                throw new Exception("PSP should be > than 0");
            }
            // passed
            return new Student(this); // new Student(new StudentBuilder());
        }

        public String getName() {
            return name;
        }

        public String getEmail() {
            return email;
        }

        public int getAge() {
            return age;
        }

        public double getPsp() {
            return psp;
        }

        public String getPhoneNo() {
            return phoneNo;
        }

        public StudentBuilder setName(String name) {
            this.name = name;
            return this;
        }

        public StudentBuilder setEmail(String email) {
            this.email = email;
            return this;
        }

        public StudentBuilder setAge(int age) {
            this.age = age;
            return this;
        }

        public StudentBuilder setPsp(double psp) {
            this.psp = psp;
            return  this;
        }

        public StudentBuilder setPhoneNo(String phoneNo) {
            this.phoneNo = phoneNo;
            return this;
        }

        public NestedStudent getNestedStudent() {
            return nestedStudent;
        }

        public StudentBuilder setNestedStudent(NestedStudent nestedStudent) {
            this.nestedStudent = nestedStudent;
            return this;
        }
    }
}