import java.util.*;
public class Gendata{
	public static void main(String args[]){
		Random r0=new Random();
		Random r1=new Random();
		double[][] means=new double[5][2];
		for(int i=0;i<5;i++){
			means[i][0]=5*r0.nextDouble();
			means[i][1]=5*r1.nextDouble();
			System.err.println(means[i][0]+","+means[i][1]);
		}
		for(int i=0;i<5;i++){
			r0=new Random();
			r1=new Random();
			for(int j=0;j<1000;j++){
				System.out.print(means[i][0]+r0.nextDouble());
				System.out.println(means[i][1]+r1.nextDouble());
			}
		}
	}
}
