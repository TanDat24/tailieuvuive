package bai11;

import java.time.LocalDate;

public class TestSTK {

	public static void main(String[] args) {
		KhachHang kh = new KhachHang("KH001", "NGuyen VAn A", 2);
		kh.themSoTietKiem("111", LocalDate.now(), 1000000, 3, (float)0.005);
		kh.themSoTietKiem("112", LocalDate.parse("2019-12-10"), 1000000, 6, (float)0.006);
		System.out.println(kh);
	}

}
