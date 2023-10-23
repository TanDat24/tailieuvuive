package bai14;

public class OderDetail {
	private int quatity;
	private Product product;
	
	public double calcTotalPrice() {
		double tien = 0;
		tien +=quatity*product.getPrice();
		return tien;
	}

	@Override
	public String toString() {
		return "OderDetail [quatity=" + quatity + ", product=" + product + "]";
	}

	public int getQuatity() {
		return quatity;
	}

	public void setQuatity(int quatity) {
		this.quatity = quatity;
	}

	public OderDetail(Product product, int quatity) {
		super();
		this.product = product;
		this.quatity = quatity;
	}
}
