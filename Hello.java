import java.util.ArrayList; 
class Software
{
    String name;
    String application;
    public Software(String name, String application)
    {
        this.name = name;
        this.application = application;
    }
    public String toString()
    {
        return "Software{" +
                "name='" + name + '\'' +
                ", application='" + application + '\'' +
                '}';
    }
}
class Computer
{
    ArrayList<Software> s;
    public Computer(ArrayList<Software> s)
    {
        this.s = s;
    }
    public void display()
    {
        for (Software software : s)
        {
            System.out.println(software);
        }
    }
}
public class Hello
{
    public static void main(String[] args)
    {
        Software ob1 = new Software("Intelli Jea","Text editor");
        Software ob2 = new Software("Anaconda","Python Programming");
        Software ob3 = new Software("Android Studio","app dev");
        ArrayList<Software> arr = new ArrayList<>();
        arr.add(ob1);
        arr.add(ob2);
        arr.add(ob3);
        Computer c = new Computer(arr);
        c.display();
    }
}
