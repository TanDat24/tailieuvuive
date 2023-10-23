package bai11;

import java.time.LocalDate;
import java.time.Period;

public class SoTietKiem {
	private String maSo;
	private LocalDate ngayMoSo;
	private double soTienGoi;
	private int kyHan;
	private float laiSuat;
	
	int tinhSoThangGoiThuc() {
		Period age = Period.between(ngayMoSo, LocalDate.now());
		int dt_nam = age.getYears();
		int dt_thang = age.getMonths();
		int mt = dt_nam*12 + dt_thang;
		return (mt/kyHan)*kyHan;
		}
	
	public double tinhTienLai() {
		return soTienGoi*tinhSoThangGoiThuc()*laiSuat;
	}
	
	@Override
	public String toString() {
		String s ="\nSTK "+ maSo +"["+ngayMoSo+"]KH "+kyHan+" thang, so thang tinh lai: "+tinhSoThangGoiThuc()+", ls "+laiSuat+", so tien:"+soTienGoi+" --> Tien lai: "+tinhTienLai();
		return s;
	}
	public SoTietKiem(String maSo, LocalDate ngayMoSo, double soTienGoi, int kyHan, float laiSuat) {
		super();
		this.maSo = maSo;
		this.ngayMoSo = ngayMoSo;
		this.soTienGoi = soTienGoi;
		this.kyHan = kyHan;
		this.laiSuat = laiSuat;
	}
	public String getMaSo() {
		return maSo;
	}
	public void setMaSo(String maSo) {
		this.maSo = maSo;
	}
	public LocalDate getNgayMoSo() {
		return ngayMoSo;
	}
	public void setNgayMoSo(LocalDate ngayMoSo) {
		this.ngayMoSo = ngayMoSo;
	}
	public double getSoTienGoi() {
		return soTienGoi;
	}
	public void setSoTienGoi(double soTienGoi) {
		this.soTienGoi = soTienGoi;
	}
	public int getKyHan() {
		return kyHan;
	}
	public void setKyHan(int kyHan) {
		this.kyHan = kyHan;
	}
	public float getLaiSuat() {
		return laiSuat;
	}
	public void setLaiSuat(float laiSuat) {
		this.laiSuat = laiSuat;
	}
	
	
}
