import java.util.ArrayList; 
class Student
{
    private String name;
    private String roll_no;
    private double cgpa;
    public Student(String name, String roll_no, double cgpa)
    {
        this.name = name;
        this.roll_no = roll_no; this.cgpa = cgpa;
    }
    public String toString()
    {
        return "Student{" + "name='" + name + '\'' + ", roll_no='" + roll_no + '\'' + ", cgpa=" + cgpa + '}';
    }
}
class Students
{
    public static void main(String[] args)
    {
        Student s[] = new Student[6];
        s[0] = new Student("Ayush","23",7.8);
        s[1] = new Student("Rohan","45",6.7);
        s[2] = new Student("Sidhhant","56",7.5);
        s[3] = new Student("Aryan","345",4.0);
        s[4] = new Student("surya","23",7.1);
        s[5] = new Student("davis","30",7.6);
        ArrayList<Student> arr = new ArrayList<>();
        for(int i = 0; i < 6; i++)
        {
            arr.add(s[i]); }
        for(int i = 0; i < arr.size();i++) {
            System.out.println(arr.get(i)); }
        arr.remove(2);
        Student p = new Student("Priyanshu","BTECH/12032/20",7.8); arr.set(2,p);
        System.out.println("\n\n");
        for(Student student : arr) {
            System.out.println(student); }
    }
}