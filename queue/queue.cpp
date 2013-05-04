/**@mainpage
*   Titov Roman Group IU 8 -21
*   Laboratory  "Dynamic structures of data. Queue"
*/
/************************************************************************/
/// @brief                       HEADERS                               ///
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
/************************************************************************/
/// @brief                       Declaration                           ///
#define MAX 3
char* queue = new char[MAX];
int qnext = 0;
int qindex = 0;
/************************************************************************/
///-------------------------Cyclic queue-------------------------------///
/**@brief                   (in Russian)
         Реализация очереди с помощью циклического массива
        ( добавить, удалить, получить значение входного элемента)       */
/************************************************************************/
void work_with_queue (void ); /// One prototype, because another function are placed in the correct order
                              /// ( every function is declared before the first use)
/************************************************************************/
///                        MAIN FUNCTION                               ///
/// {
int main(void)
{
  work_with_queue();
  return 0;
}
/// }
/************************************************************************/
/// Function insert in queue @brief (Element entering in queue)
/// {
void push( int i )
{
	if(( qnext + 1 == qindex ) || (( qnext + 1 ) == MAX && !qindex ))
	{
		printf( "No possition!\n" );
		return;
	}
	queue[ qnext ] = i; /// Recording
	qnext++;            /// Replace possition of recording
	if( qnext == MAX )
		qnext = 0;      /// Cyclic transition
}
/// }
/************************************************************************/
/// Function pop @brief ( Element extraction from queue )
/// {
int pop( void)
{
	if( qindex == MAX )
		qindex = 0;             /// Cyclic transition
	if( qindex == qnext )
	{
		printf( "Queue if empty!\n" );
		return 0;
	}
	qindex++;                   /// Shift of a position of reading
	return queue[ qindex - 1 ]; /// Reading
}
/// }
/************************************************************************/
/// @page Function work_with_queue
/// { 
void work_with_queue (void )
{
	register unsigned char c; /// Very fast sending
	int t;	
	queue[ MAX + 1] = '\0';
	fflush(stdin); /// Free stdin buffer
	
	/// To accept entered symbols before pressing (Enter)
	
	for( c =' ', t = 0; t < 32000 && c != '\r'; ++t ) { /// Before carriage return
		if( kbhit() ) { ///  The kbhit function returns nonzero value, if a key
			            ///  it is pressed. Otherwise return 0
			c = getch();
			push(c);
		}
		
		printf("%d ", t);
		if(c == '\r') {
			/// To display contents of the buffer of the keyboard and to release the buffer
			printf("\n");

			while(( c = pop()) != '\0')
				printf("%c", c);

			printf("\n");
		}
	}
	delete [] queue;
}
/**************************END_PROGRAM***********************************/



