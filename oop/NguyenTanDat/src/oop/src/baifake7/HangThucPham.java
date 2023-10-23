package baifake7;

import java.text.DecimalFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class HangThucPham {
	private String maHang;
	private String tenHang;
	private double donGia;
	private LocalDate ngaySX;
	private LocalDate ngayHH;
	public HangThucPham(String maHang, String tenHang, double donGia, LocalDate ngaySX, LocalDate ngayHH) throws Exception {
		super();
		if(maHang.trim().equals(""))
			throw new Exception("Loi: Mo rong!");
		this.maHang = maHang;
		this.tenHang = tenHang;
		this.donGia = donGia;
		this.ngaySX = ngaySX;
		this.ngayHH = ngayHH;
	}
	public String getMaHang() {
		return maHang;
	}
	public void setMaHang(String maHang) throws Exception {
		if(maHang.trim().equals(""))
			throw new Exception("Loi: Mo rong!");
		this.maHang = maHang;
	}
	public String getTenHang() {
		return tenHang;
	}
	public void setTenHang(String tenHang) {
		if(tenHang.trim().equals(""))
			this.tenHang = "xxx";
		else
			this.tenHang = tenHang;
	}
	public double getDonGia() {
		return donGia;
	}
	public void setDonGia(double donGia) throws Exception {
		if(donGia<0)
			throw new Exception("Loi: don gia am");
		this.donGia = donGia;
	}
	public LocalDate getNgaySX() {
		return ngaySX;
	}
	public void setNgaySX(LocalDate ngaySX) {
		if(ngaySX.isBefore(LocalDate.now()))
			this.ngaySX = ngaySX;
		else
			this.ngaySX = LocalDate.now();
	}
	public LocalDate getNgayHH() {
		return ngayHH;
	}
	public void setNgayHH(LocalDate ngayHH) {
		if(ngaySX.isAfter(ngaySX))
			this.ngayHH = ngayHH;
		else
			this.ngayHH = ngaySX;
	}
	public boolean hetHan() {
		if(ngayHH.isBefore(ngayHH))
			return true;
		else
			return false;
	}
	@Override
	public String toString() {
		DateTimeFormatter df = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		DecimalFormat af = new DecimalFormat("#,##00.00");
		return String.format("%-7s %-10s %15sVND %-13s %-13s",maHang,tenHang,af.format(donGia),df.format(ngaySX),df.format(ngayHH));
	}
}
