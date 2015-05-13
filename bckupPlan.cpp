#include <QImage>
#include <cstdlib>
#include <QColor>
#include <iostream>
#include <string>
using namespace std;

int main( int argc , char *argv[ ] ) {

   string file1;
   cout << "First Image: ";
   getline (cin, file1);
   
   string file2;
   cout << "\n Second Image: ";
   getline (cin, file2);
   
   QImage firstImage ( file1 ) ;
   QImage secondImage ( file2 ) ;
   double totaldiff = 0.0 ; //holds the number of different pixels
   int h = firstImage.height( ) ;
   int w = firstImage.width( ) ;
   int hsecond = secondImage.height( ) ;
   int wsecond = secondImage.width( ) ;
   if ( w != wsecond || h != hsecond ) {
      cerr << "Error, pictures must have identical dimensions!\n" ;
      return 2 ;
   } 
   for ( int y = 0 ; y < h ; y++ ) {
      uint *firstLine = ( uint* )firstImage.scanLine( y ) ;
      uint *secondLine = ( uint* )secondImage.scanLine( y ) ;
      for ( int x = 0 ; x < w ; x++ ) {
	 uint pixelFirst = firstLine[ x ] ;
	 int rFirst = qRed( pixelFirst ) ;
	 int gFirst = qGreen( pixelFirst ) ;
	 int bFirst = qBlue( pixelFirst ) ;
	 uint pixelSecond = secondLine[ x ] ;
	 int rSecond = qRed( pixelSecond ) ;
	 int gSecond = qGreen( pixelSecond ) ;
	 int bSecond = qBlue( pixelSecond ) ;
	 totaldiff += std::abs( rFirst - rSecond ) / 255.0 ;
	 totaldiff += std::abs( gFirst - gSecond ) / 255.0 ;
	 totaldiff += std::abs( bFirst -bSecond ) / 255.0 ;
      }
   }
   cout << "The difference of the two pictures is " <<
      (totaldiff * 100)  / (w * h * 3)  << " % !\n" ;
   return 0 ;
}
