package bai10;

import java.util.Arrays;

public class LopHocPhan {
	private String maLHP;
	private String tenLHP;
	private String tenGV;
	private String thongTinLopHoc;
	private SinhVien[] dsSV;
	
	public int getSoLuongSinhVien() {
		return dsSV.length;
	}
	
	@Override
	public String toString() {
		String s = "- Ma LHP: "+maLHP
				+"\n- Ten LHP: "+tenLHP
				+"\n- GV giang day: "+tenGV
				+"\n- Thong tin buoi hoc: "+thongTinLopHoc
				+"\n\nDanh sach sinh vien ";
		for(SinhVien sv : dsSV) {
			s+="\n"+ sv;
		}
		s+="\nTong so sinh vien: "+ getSoLuongSinhVien();
		return s;
	}


	public LopHocPhan(String maLHP, String tenLHP, String tenGV, String thongTinLopHoc, SinhVien[] dsSV) {
		super();
		this.maLHP = maLHP;
		this.tenLHP = tenLHP;
		this.tenGV = tenGV;
		this.thongTinLopHoc = thongTinLopHoc;
		this.dsSV = dsSV;
	}
	public String getMaLHP() {
		return maLHP;
	}
	public void setMaLHP(String maLHP) {
		this.maLHP = maLHP;
	}
	public String getTenLHP() {
		return tenLHP;
	}
	public void setTenLHP(String tenLHP) {
		this.tenLHP = tenLHP;
	}
	public String getTenGV() {
		return tenGV;
	}
	public void setTenGV(String tenGV) {
		this.tenGV = tenGV;
	}
	public String getThongTinLopHoc() {
		return thongTinLopHoc;
	}
	public void setThongTinLopHoc(String thongTinLopHoc) {
		this.thongTinLopHoc = thongTinLopHoc;
	}
	public SinhVien[] getDsSV() {
		return dsSV;
	}
	public void setDsSV(SinhVien[] dsSV) {
		this.dsSV = dsSV;
	}
}
