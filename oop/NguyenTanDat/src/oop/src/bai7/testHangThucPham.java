package bai7;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class testHangThucPham {

	public static void main(String[] args) {
		DateTimeFormatter df = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		try {
			hangThucPham h1 = new hangThucPham("001","Gao",100000,LocalDate.parse("28/09/2023", df),LocalDate.parse("30/09/2023", df));
			hangThucPham h2 = new hangThucPham("002","Mi",5000,LocalDate.parse("28/09/2023", df),LocalDate.parse("30/09/2023", df));
			hangThucPham h3 = new hangThucPham("003","Can sa",5000,LocalDate.parse("28/09/2023", df),LocalDate.parse("30/09/2023", df));
//			Scanner sc = new Scanner(System.in);
//			System.out.println("Ten san pham: ");
//			h3.setTenHang(sc.nextLine());
//			h3.setDonGia(sc.nextDouble());
//			
			System.out.println(h1);
			System.out.println(h2);
			System.out.println(h3);
		}catch(Exception e) {
			e.printStackTrace();
			}
		}
}
	