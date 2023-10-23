package bai13;

import java.util.Arrays;

public class DanhSachCongNhan {
	private int maxSize;
	private int minSize;
	private CongNhan[] cns;
	
    public DanhSachCongNhan(int maxSize) {
        this.maxSize = maxSize;
        this.cns = new CongNhan[maxSize]; // Initialize the array with the specified maxSize
        this.minSize = 0;
    }
	public boolean addCN(CongNhan cn) {
		if(minSize>=maxSize) 
			return false;
		cns[minSize] = cn;
		minSize++;
		return true;
	}
	@Override
	public String toString() {
		return "DanhSachCongNhan [cns=" + Arrays.toString(cns) + "]";
	}
	
	public int slcn() {
		return minSize;
	}
	public boolean xoa(int maCN) {
		for (int i = 0; i < cns.length; i++) {
			if(cns[i].getMaCN()==maCN) {
				for (int j = 0; j < cns.length-1; j++) {
					cns[j] = cns[j+1];
				}
				minSize--;
				return true;
			}
		}
		return false;
	}
	public int slDanhSach() {
		int soluong = 0;
		for (CongNhan congNhan : cns) {
			if(congNhan.getmSoSp()>200) {
				soluong++;
			}
		}
		return soluong;
	}
	public void sapxep() {
		Arrays.sort(cns,0,minSize,(cn1,cn2)->Integer.compare(cn2.getmSoSp(), cn1.getmSoSp()));
	}
	public int getMaxSize() {
		return maxSize;
	}

	public void setMaxSize(int maxSize) {
		this.maxSize = maxSize;
	}

	public int getMinSize() {
		return minSize;
	}

	public void setMinSize(int minSize) {
		this.minSize = minSize;
	}

	public CongNhan[] getCn() {
		return cns;
	}

	public void setCn(CongNhan[] cn) {
		this.cns = cn;
	}
	
	
}
