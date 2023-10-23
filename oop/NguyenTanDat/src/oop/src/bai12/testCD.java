package bai12;

import java.util.Scanner;

public class testCD {

	public static void main(String[] args) throws Exception {
		try (Scanner sc = new Scanner(System.in)) {
			System.out.println("so luong CD");
			int max = sc.nextInt();
			
			listCD ls = new listCD(max);
			
			int chon;
			do {
				 System.out.println("\nMENU:");
			        System.out.println("1. Thêm CD");
			        System.out.println("2. Xóa CD theo mã");
			        System.out.println("3. Hiển thị danh sách CD");
			        System.out.println("4. Tính số lượng CD");
			        System.out.println("5. Tính tổng giá thành");
			        System.out.println("6. Tìm kiếm theo mã CD");
			        System.out.println("7. Sắp xếp giảm dần theo giá thành");
			        System.out.println("8. Sắp xếp tăng dần theo tựa CD");
			        System.out.println("0. Thoát");

			        System.out.print("Chọn một tùy chọn: ");
			        chon = sc.nextInt();
			        switch (chon) {
					case 1: {
						{
							System.out.println("Nhap ma CD:");
							int maCD = sc.nextInt();
							System.out.println("Nhap tua CD: ");
							String tuaCD = sc.nextLine();
							System.out.println("Nhap so bai: ");
							int soBaiHat = sc.nextInt();
							System.out.println("Nhap gia thanh: ");
							int giaThanh = sc.nextInt();
							
							CD newCD = new CD(maCD, tuaCD, soBaiHat, giaThanh);
							boolean addCD = ls.addCD(newCD);
							if(addCD)
								System.out.println("them thanh cong");
							else {
								System.out.println("khong them dc");
							}
						}break;
					}
					case 2: {
						{
							int maCD;
							System.out.println("Nhap ma CD can xoa");
							maCD = sc.nextInt();
							boolean xoaCD = ls.xoa(maCD);
							if(xoaCD) {
								System.out.println("da xoa");
							} else {
								System.out.println("khong xoa dc");
							}
						}break;
					}
					case 3: {
						 	System.out.println("Danh sách CD:");
						 	System.out.println(ls.toString());
					}break;
					case 4: {
						int sl = ls.slCD();
						System.out.println("so luong cd: "+sl);
					}break;
					case 5: {
						double tongTien = ls.tinTien();
						System.out.println("Tong tien la: "+tongTien);
					}break;
					case 6: {
						System.out.println("spa xep theo gia:");
						ls.sortByGia();
					}break;
					case 7: {
						System.out.println("spa xep theo tua CD:");
						ls.sortByTua();
					}break;
					case 0: {
						System.out.println("Kết thúc chương trình.");
					}break;
					default:
						throw new IllegalArgumentException("Unexpected value: " + chon);
					}
			} while (chon!=0);
		}
	}
}
