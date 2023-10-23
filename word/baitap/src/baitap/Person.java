package baitap;

public abstract class Person{
    private String name;
    private String address;
    
    public Person(String name, String address){
        this.name = name;
        this.address = address;
    }
    
    public abstract void display();
    
    public String getName(){
        return name;
    }
    public void setName(){
    }
    
    public String getAddress(){
        return address;
    }
    public void setAddress(){
    }
}
