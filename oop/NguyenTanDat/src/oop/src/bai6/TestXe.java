package bai6;


public class TestXe {
	public static void tuade() {
		System.out.printf("%-20s %-20s %-20s %-20s %-20s\n","Ten chu xe","Loai xe","Dung tich","Tri gia","Thue");
		System.out.printf("===============================================================================================\n");
	}
	public static void main(String[] args) throws Exception {
		try {
			tuade();
			ThongTinDangKyXe xe1 = new ThongTinDangKyXe("nguyen van a", "Honda",35000000.00, 100);
			ThongTinDangKyXe xe2 = new ThongTinDangKyXe("nguyen van t", "ford",250000000.00, 3000);
			ThongTinDangKyXe xe3 = new ThongTinDangKyXe("nguyen van h", "vinfast",1000000000.00, 1500);
			
			System.out.println(xe1);
			System.out.println(xe2);
			System.out.println(xe3);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
