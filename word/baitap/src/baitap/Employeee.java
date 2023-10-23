package baitap;

public abstract class Emloyeee implements IEmployee{
    private String name;
    private int paymentPerHour;
    
    public Employee(String name, int paymentPerHour){
        this.name = name;
        this.paymentPerHour = paymentPerHour;
    }
    
    @Override
    public String getName(){
        return name;
    }
    
    public void setName(String name){
        this.name = name;
    }
    
    public int getPaymentPerhour(){
        return paymentPerHour;
    }
    
    public void paymentPerHour(int paymentPerHour){
        this.paymentPerHour = paymentPerHour;                                      
    }
}
