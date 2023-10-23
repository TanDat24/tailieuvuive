package bai11;

import java.time.LocalDate;
import java.util.Arrays;

public class KhachHang {
	private String maKH;
	private String hoTenKH;
	private SoTietKiem[] dsSoTietKiem;
	private int soLuongSoHienCo;
	
	public KhachHang(String maKH, String hoTenKH, int soLuongToiDa) {
		super();
		this.maKH = maKH;
		this.hoTenKH = hoTenKH;
		dsSoTietKiem = new SoTietKiem[soLuongToiDa];
		this.soLuongSoHienCo = 0;
	}
	
	public boolean themSoTietKiem(String maSo,LocalDate ngayMoSo,double soTienGoi,int kyHan,float laiSuat) {
		if(soLuongSoHienCo == dsSoTietKiem.length)return false;
		SoTietKiem stk= new SoTietKiem(maSo, ngayMoSo, soTienGoi, kyHan, laiSuat);
		
		dsSoTietKiem[soLuongSoHienCo] = stk;
		soLuongSoHienCo++;
		return true;
	}
	
	@Override
	public String toString() {
		String s = "Khach hang: "+maKH+" - "+hoTenKH+"\n"+ Arrays.toString(dsSoTietKiem);
		return s;
	}

	public String getMaKH() {
		return maKH;
	}
	public void setMaKH(String maKH) {
		this.maKH = maKH;
	}
	public String getHoTenKH() {
		return hoTenKH;
	}
	public void setHoTenKH(String hoTenKH) {
		this.hoTenKH = hoTenKH;
	}
	public SoTietKiem[] getDsSoTietKiem() {
		return dsSoTietKiem;
	}
	public void setDsSoTietKiem(SoTietKiem[] dsSoTietKiem) {
		this.dsSoTietKiem = dsSoTietKiem;
	}
	public int getSoLuongSoHienCo() {
		return soLuongSoHienCo;
	}
	public void setSoLuongSoHienCo(int soLuongSoHienCo) {
		this.soLuongSoHienCo = soLuongSoHienCo;
	}
	
	
}
