#include "constants.h"
#include "setAddress.h"
#include "writeData.h"
#include "writeCommand.h"
void clearPCD8544(void)
{
    uint8_t col, page;
 
    for (page = 0; page < 6; page++)
    {
       
        for(col = 0; col < 84; col++)
        {
            setAddress(col, page);
            writeData(0x00);
        }
    }
}
