package bai12;

import java.util.Arrays;

public class listCD {
	private int max;
	private int min;
	private CD[] cds;
	public listCD(int max) {
		super();
		this.max = max;
		this.min = 0;
		this.cds = new CD[max];
	}
	
	public boolean addCD(CD cd) {
		if(min>=max)
			return false;
		for (int i = 0; i < this.cds.length; i++) {
			if(cd.getMaCD()== cds[i].getMaCD())
				return false;
		}
		cds[min] = cd;
		min++;
		return true;
	}

	public int getMax() {
		return max;
	}

	public void setMax(int max) {
		this.max = max;
	}

	public int getMin() {
		return min;
	}

	public void setMin(int min) {
		this.min = min;
	}

	public CD[] getCds() {
		return cds;
	}

	public void setCds(CD[] cds) {
		this.cds = cds;
	}

	@Override
	public String toString() {
		return "listCD [max=" + max + ", min=" + min + ", cds=" + Arrays.toString(cds) + "]";
	}
	
	
	public int slCD() {
		return min;
	}
	
	public boolean xoa(int macd) {
		for (int i = 0; i < cds.length; i++) {
			if(cds[i].getMaCD() == macd) {
				for (int j = 0; j < cds.length -1; j++) {
					cds[j] = cds[j+1];
				}
				min--;
				return true;
			}
		}
		return false;
	}
	public double tinTien() {
		double tien = 0.0;
		for (int i = 0; i < cds.length; i++) {
			tien += cds[i].getGiaThanh();
		}
		return tien;
	}
	public CD tim(int macd) {
		for (int i = 0; i < cds.length; i++) {
			if(cds[i].getMaCD() == macd) {
				return cds[i];
			}
		}
		return null;
	}
	public void sortByGia() {
		Arrays.sort(cds,0,min,(cd1,cd2)->Double.compare(cd2.getGiaThanh(), cd1.getGiaThanh()));
	}
	public void sortByTua() {
		Arrays.sort(cds,0,min,(cd1,cd2)->cd1.getTuaCD().compareTo(cd2.getTuaCD()));
	}
	
}
