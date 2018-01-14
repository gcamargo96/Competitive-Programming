import java.io.*;
import java.math.*;
import java.util.*;

class B{

	static BigInteger fastpow(BigInteger b, BigInteger e){
		if(e.equals(BigInteger.valueOf(0))) return BigInteger.valueOf(1);

		BigInteger x = fastpow(b, e.divide(BigInteger.valueOf(2)));
		if((e.mod(BigInteger.valueOf(2))).equals(BigInteger.valueOf(0))){
			return x.multiply(x);
		}
		else{
			return b.multiply(x.multiply(x));
		}
	}

	static void precalc(BigInteger fat[]){
		fat[0] = BigInteger.valueOf(1);

		for(int i = 1; i < 402; i++){
			fat[i] = fat[i-1].multiply(BigInteger.valueOf(i));
		}
	}

	public static void main(String[] args) throws Exception{
		BigInteger fat[] = new BigInteger[402];
		precalc(fat);

		Scanner input = new Scanner(System.in);
		BigInteger b = input.nextBigInteger();
		BigInteger e = input.nextBigInteger();

		BigInteger res = fat[n.intValue()].multiply(fat[2*n.intValue()].divide(fat[n.intValue()].multiply(fat[n.intValue()])));

		input.close();
	}
}
