package bai13;

public class CongNhan {	
	private int maCN;
	private String mHo;
	private String mTen;
	private int mSoSp;
	public CongNhan(int maCN,String mHo, String mTen, int mSoSp) {
		super();
		setMaCN(maCN);
		setmHo(mHo);
		setmTen(mTen);
		setmSoSp(mSoSp);
	}
	public int getMaCN() {
		return maCN;
	}
	public void setMaCN(int maCN) {
		this.maCN = maCN;
	}
	public String getmHo() {
		return mHo;
	}
	public void setmHo(String mHo) {
		this.mHo = mHo;
	}
	public String getmTen() {
		return mTen;
	}
	public void setmTen(String mTen) {
		this.mTen = mTen;
	}
	public int getmSoSp() {
		return mSoSp;
	}
	public void setmSoSp(int mSoSp) {
		if(mSoSp>0)
		this.mSoSp = mSoSp;
	}
	public double tinhLuong() {
		double luong = 0.0;
		if(mSoSp>=1 && mSoSp<=199) {
			luong = mSoSp*0.5;
		} else if(mSoSp >=200 && mSoSp <= 399) {
			luong = mSoSp*0.55;
		} else if(mSoSp >=400 && mSoSp <= 599) {
			luong = mSoSp*0.6;
		} else {
			luong = mSoSp*0.65;
		}
		return luong;
	}
	@Override
	public String toString() {
		return "CongNhan [maCN=" + maCN + ", mHo=" + mHo + ", mTen=" + mTen + ", mSoSp=" + mSoSp + "]";
	}
	
	
	
}
