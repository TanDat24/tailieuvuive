package bai13;

import java.util.Scanner;

public class testCongNhan {

	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int max;
			max = sc.nextInt();
			DanhSachCongNhan dscn = new DanhSachCongNhan(max);
			
			int chon;
			do {
				System.out.println("1.them");
				System.out.println("2.in");
				System.out.println("3.so luong cong nhan");
				System.out.println("4.xoa");
				System.out.println("5.cong nhan sp tren 200");
				System.out.println("6.sap xep");
				System.out.println("0.thoat");
				System.out.println("Nhap so muon thuc hien");
				chon = sc.nextInt();
				switch (chon) {
				case 1: {
					System.out.println("Nhap ma cong nhan");
					int macn = sc.nextInt();
					System.out.println("Nhap ho");
					String hocn = sc.next();
					System.out.println("Nhap ten");
					String tencn = sc.next();
					System.out.println("Nhap so san pham");
					int sosp = sc.nextInt();
					
					CongNhan newcn = new CongNhan(macn, hocn, tencn, sosp);
					boolean addcn = dscn.addCN(newcn);
					if(addcn) {
						System.out.println("them thanh cong");
					}else {
						System.out.println("khong them dc");
					}
				}break;
				case 2: {
					System.out.println("Danh sach cong nhan");
					System.out.println(dscn.toString());
				}break;
				case 3: {
					int sl = dscn.slcn();
					System.out.println("so luong la: "+sl);
				}break;
				case 4: {
					System.out.println("Nhap ma so cong nhan muon xoa: ");
					int maso = sc.nextInt();
					boolean xoa = dscn.xoa(maso);
					if(xoa) {
						System.out.println("da xoa");
					}else {
						System.out.println("Khong xoa");
					}
				}break;
				case 5: {
					int socn200 = dscn.slDanhSach();
					System.out.println("So cong nhan co so san pham tren 200: "+socn200);
				}break;
				case 6: {
					System.out.println("sn da sap xep: ");
					dscn.sapxep();
				}break;
				case 0: {
					System.out.println("Kết thúc chương trình.");
				}break;
				default:
					throw new IllegalArgumentException("Unexpected value: " + chon);
				}
			} while (chon != 0);
		}
	}

}
