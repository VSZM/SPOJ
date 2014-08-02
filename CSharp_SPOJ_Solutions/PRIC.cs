using System;
using System.IO;
using System.Text;

class ContestUtil
{
	static Stream ReadStream;
	static int Idx, Size, BytesRead;
	static byte[] Buffer;
	public static void Initialze()
	{
		ReadStream = Console.OpenStandardInput();
		Idx = BytesRead = 0;
		Size = 1 << 17;
		Buffer = new byte[Size];
		ReadConsoleInput();
	}
	public static int ReadInt()
	{
		unchecked
		{
			byte _ReadByte;
			//For trimming
			do
			{
				_ReadByte = ReadByte();
			}
			while ( _ReadByte < '-' );
			bool neg = false;
			//Checking sign of number
			if ( _ReadByte == '-' )
			{
				neg = true;
				_ReadByte = ReadByte();
			}
			int m = _ReadByte - '0';
			while ( true )
			{
				_ReadByte = ReadByte();
				if ( _ReadByte < '0' )
					break;
				m = m * 10 + (_ReadByte - '0');
			}
			if ( neg )
				return -m;
			return m;
		}
	}

	public static ulong ReadUlong()
	{
		unchecked
		{
			byte _ReadByte;
			//For trimming
			do
			{
				_ReadByte = ReadByte();
			}
			while ( _ReadByte < '0' );
			//Checking sign of number
			ulong m = ( ulong )(_ReadByte - '0');
			while ( true )
			{
				_ReadByte = ReadByte();
				if ( _ReadByte < '0' )
					break;
				m = m * 10 + ( ulong )(_ReadByte - '0');
			}
			return m;
		}
	}

	public static bool EOF()
	{
		return Buffer[Idx] == 0;
	}

	private static void ReadConsoleInput()
	{
		Idx = 0;
		BytesRead = ReadStream.Read( Buffer, 0, Size - 3 );
		Buffer[BytesRead] = 0;
		Buffer[BytesRead + 1] = 0;
	}
	private static byte ReadByte()
	{
		if ( Idx >= BytesRead )
			ReadConsoleInput();
		return Buffer[Idx++];
	}
	public static void Dispose()
	{
		ReadStream.Close();
	}

}
class PRIC
{
	private const int M = 25165824;
	static uint sqrt32(ulong n)
	{
		uint c = 0x8000;
		uint g = 0x8000;

		for ( ; ; )
		{
			if ( g * g > n )
				g ^= c;
			c >>= 1;
			if ( c == 0 )
				return g;
			g |= c;
		}
	}
    /*
	static void Main(string[] args)
	{
		DateTime end_time = DateTime.Now + TimeSpan.FromSeconds( 24 );
		ContestUtil.Initialze();

		unchecked
		{
			bool[] primes = new bool[M];
			bool is_p;
			ulong act;
			uint sqra;



			for ( int i = 0 ; i < M ; i++ )
				primes[i] = true;


			primes[0] = primes[1] = false;
			for ( int i = 2 ; i < M ; ++i )
			{
				if ( primes[i] == true )
					for ( int j = i + i ; j < M ; j += i )
						primes[j] = false;
			}


			do
			{

				act = ContestUtil.ReadUlong();

				if ( act % 2 == 1 )// actual number is odd
				{
					if ( act < M )// actual number is predecided
					{
						is_p = primes[act];
					}
					else
					{

						sqra = sqrt32( act ) + 1;
						sqra = Math.Min( sqra, M );
						is_p = true;

						for ( int i = 3 ; i < sqra ; ++i )
						{
							if ( primes[i] && act % ( ulong )i == 0 )
							{
								is_p = false;
								break;
							}
						}

					}
				}
				else// even numbers are not primes except 2
					if ( act != 2 )
						is_p = false;
					else
						is_p = true;
				Console.Write( is_p ? '1' : '0' );
			} while ( !ContestUtil.EOF() && DateTime.Now < end_time );
		}
		ContestUtil.Dispose();
		//Console.WriteLine( "1111111111111111111111111111111111111" );
	}*/
}