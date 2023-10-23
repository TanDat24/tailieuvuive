package bai4;

public class DiemSinhVien {
	private int maSv;
	private String tenSv;
	private double DiemLt;
	private double DiemTh;
	public DiemSinhVien() {
		// TODO Auto-generated constructor stub
	}
	public DiemSinhVien(int maSv, String tenSv, double diemLt, double diemTh) throws Exception {
		super();
		setMaSv(maSv);
		setTenSv(tenSv);
		setDiemLt(diemLt);
		setDiemTh(diemTh);
	}
	public int getMaSv() {
		return maSv;
	}
	public void setMaSv(int maSv) throws Exception {
		if(maSv <= 0) {
			throw new Exception("Ma khong dung!");
		}
		this.maSv = maSv;
	}
	public String getTenSv() {
		return tenSv;
	}
	public void setTenSv(String tenSv) throws Exception {
		if(tenSv.trim().equals(""))
			throw new Exception("Ten khong dung!");
		this.tenSv = tenSv;
	}
	public double getDiemLt() {
		return DiemLt;
	}
	public void setDiemLt(double diemLt) throws Exception {
		if(diemLt < 0 || diemLt >10) {
			throw new Exception("Diem khong dung!");
		}
		DiemLt = diemLt;
	}
	public double getDiemTh() {
		return DiemTh;
	}
	public void setDiemTh(double diemTh) throws Exception {
		if(diemTh < 0 || diemTh >10) {
			throw new Exception("Diem khong dung!");
		}
		DiemTh = diemTh;
	}
	
	public double DiemTB() {
		return (DiemLt+DiemTh)/2;
	}
	@Override
	public String toString() {
		return String.format("%-10s %-25s %10.2f %10.2f %10.2f",maSv,tenSv,DiemLt,DiemTh,DiemTB());
	}
}
