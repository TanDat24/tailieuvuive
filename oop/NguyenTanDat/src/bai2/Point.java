package bai2;

public class Point {
	private float x;
	private float y;
	public Point() {
		super();
	}
	public Point(float x, float y) {
		this.x = x;
		this.y = y;
	}
	public float getX() {
		return x;
	}
	public void setX(float x) {
		this.x = x;
	}
	public float getY() {
		return y;
	}
	public void setY(float y) {
		this.y = y;
	}
	public Point negate() {
		Point tmp = new Point();
		tmp.x = -this.x;
		tmp.y = -this.y;
		return tmp;
	}
	public double getDistance() {
		return Math.sqrt(Math.pow(this.x,2))+Math.sqrt(Math.pow(this.y,2));
	}
}
