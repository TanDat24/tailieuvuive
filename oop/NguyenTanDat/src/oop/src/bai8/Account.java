package bai8;

public class Account {
	private long accNum;
	private String name;
	private double balance;
	private final double RATE = 0.035;
	 public Account() {
	        this(999999, "chưa xác định", 50000);
	    }
	public Account(long accNum, String name, double balance) {
		super();
		this.accNum = accNum;
		this.name = name;
		this.balance = balance;
	}
	public Account(long accNum, String name) {
		super();
		this.accNum = accNum;
		this.name = name;
	}
	public long getAccNum() {
		return accNum;
	}
	public void setAccNum(long accNum) {
		if()
		this.accNum = accNum;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	public double getRATE() {
		return RATE;
	}
	
	
	
}
