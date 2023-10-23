package bai3;


public class HinhTru {
	private double x;
	private double y;
	public HinhTru() {
		super();
	}
	public HinhTru(double x, double y) {
		this.x = x;
		this.y = y;
	}
	public double getX() {
		return x;
	}
	public void setX(double x) {
		this.x = x;
	}
	public double getY() {
		return y;
	}
	public void setY(double y) {
		this.y = y;
	}
	public double SXungQuanh() {
		return (2*(Math.PI)*this.x*this.y);
	}
	public double SToanPhan() {
		return (2*Math.PI*Math.pow(this.x, 2) + 2*Math.PI*this.x*this.y);
	}
	public double TheTich() {
		return (Math.PI*Math.pow(this.x, 2)*this.y);
	}
}
