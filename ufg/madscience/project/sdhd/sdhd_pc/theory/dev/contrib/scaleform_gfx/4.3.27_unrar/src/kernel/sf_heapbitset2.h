// File Line: 131
// RVA: 0x999DA0
void __fastcall Scaleform::Heap::BitSet2::MarkBusy(unsigned int *buf, unsigned __int64 start, unsigned __int64 num)
{
  char v5; // cl
  int v6; // eax
  unsigned int *v7; // r8

  if ( num > 1 )
  {
    if ( num == 2 )
    {
      v5 = 2 * start;
      v7 = &buf[start >> 4];
      v6 = 2;
    }
    else
    {
      if ( num - 3 > 2 )
      {
        buf[start >> 4] = (3 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
        buf[(start + 1) >> 4] = (3 << ((2 * (start + 1)) & 0x1E)) | buf[(start + 1) >> 4] & ~(3 << ((2 * (start + 1)) & 0x1E));
        if ( num >= 0x26 )
        {
          buf[(start + 2) >> 4] = (3 << ((2 * (start + 2)) & 0x1E)) | buf[(start + 2) >> 4] & ~(3 << ((2 * (start + 2)) & 0x1E));
          buf[(2 * start + 37) >> 5] = num;
        }
        else
        {
          buf[(start + 2) >> 4] = ((unsigned int)(num - 6) >> 4 << ((2 * (start + 2)) & 0x1E)) | buf[(start + 2) >> 4] & ~(3 << ((2 * (start + 2)) & 0x1E));
          buf[(start + 3) >> 4] = buf[(start + 3) >> 4] & ~(3 << ((2 * (start + 3)) & 0x1E)) | ((((unsigned int)(num - 6) >> 2) & 3) << ((2 * (start + 3)) & 0x1E));
          buf[(start + 4) >> 4] = ((((_DWORD)num - 6) & 3) << ((2 * (start + 4)) & 0x1E)) | buf[(start + 4) >> 4] & ~(3 << ((2 * (start + 4)) & 0x1E));
        }
        goto LABEL_10;
      }
      buf[start >> 4] = (3 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      v5 = 2 * (start + 1);
      v6 = num - 3;
      v7 = &buf[(start + 1) >> 4];
    }
    *v7 = (v6 << (v5 & 0x1E)) | *v7 & ~(3 << (v5 & 0x1E));
LABEL_10:
    buf[(start + num - 1) >> 4] = (1 << ((2 * (start + num - 1)) & 0x1E)) | buf[(start + num - 1) >> 4] & ~(3 << ((2 * (start + num - 1)) & 0x1E));
    return;
  }
  buf[start >> 4] = (1 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
}

// File Line: 178
// RVA: 0x999900
void __fastcall Scaleform::Heap::BitSet2::MarkBusy(
        unsigned int *buf,
        unsigned __int64 start,
        unsigned __int64 num,
        unsigned __int64 alignShift)
{
  unsigned int v5; // r9d
  unsigned int *v6; // r8
  unsigned int *v7; // r8

  switch ( num )
  {
    case 0ui64:
    case 1ui64:
      buf[start >> 4] = (1 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      break;
    case 2ui64:
      buf[start >> 4] = (2 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      buf[(start + 1) >> 4] = (((_DWORD)alignShift + 1) << ((2 * (start + 1)) & 0x1E)) | buf[(start + 1) >> 4] & ~(3 << ((2 * (start + 1)) & 0x1E));
      break;
    case 3ui64:
    case 4ui64:
    case 5ui64:
      buf[start >> 4] = (3 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      buf[(start + 1) >> 4] = (((_DWORD)num - 3) << ((2 * (start + 1)) & 0x1E)) | buf[(start + 1) >> 4] & ~(3 << ((2 * (start + 1)) & 0x1E));
      buf[(start + num - 1) >> 4] = (((_DWORD)alignShift + 1) << ((2 * (start + num - 1)) & 0x1E)) | buf[(start + num - 1) >> 4] & ~(3 << ((2 * (start + num - 1)) & 0x1E));
      break;
    case 6ui64:
    case 7ui64:
      buf[start >> 4] = (3 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      buf[(start + 1) >> 4] = (3 << ((2 * (start + 1)) & 0x1E)) | buf[(start + 1) >> 4] & ~(3 << ((2 * (start + 1)) & 0x1E));
      buf[(start + 2) >> 4] &= ~(3 << ((2 * (start + 2)) & 0x1E));
      buf[(start + 3) >> 4] &= ~(3 << ((2 * (start + 3)) & 0x1E));
      buf[(start + 4) >> 4] = (((_DWORD)num - 6) << ((2 * (start + 4)) & 0x1E)) | buf[(start + 4) >> 4] & ~(3 << ((2 * (start + 4)) & 0x1E));
      buf[(start + num - 1) >> 4] = (((_DWORD)alignShift + 1) << ((2 * (start + num - 1)) & 0x1E)) | buf[(start + num - 1) >> 4] & ~(3 << ((2 * (start + num - 1)) & 0x1E));
      break;
    default:
      buf[start >> 4] = (3 << ((2 * start) & 0x1E)) | buf[start >> 4] & ~(3 << ((2 * start) & 0x1E));
      buf[(start + 1) >> 4] = (3 << ((2 * (start + 1)) & 0x1E)) | buf[(start + 1) >> 4] & ~(3 << ((2 * (start + 1)) & 0x1E));
      if ( num >= 0x26 )
      {
        buf[(start + 2) >> 4] = (3 << ((2 * (start + 2)) & 0x1E)) | buf[(start + 2) >> 4] & ~(3 << ((2 * (start + 2)) & 0x1E));
        buf[(2 * start + 37) >> 5] = num;
      }
      else
      {
        buf[(start + 2) >> 4] = ((unsigned int)(num - 6) >> 4 << ((2 * (start + 2)) & 0x1E)) | buf[(start + 2) >> 4] & ~(3 << ((2 * (start + 2)) & 0x1E));
        buf[(start + 3) >> 4] = ((((unsigned int)(num - 6) >> 2) & 3) << ((2 * (start + 3)) & 0x1E)) | buf[(start + 3) >> 4] & ~(3 << ((2 * (start + 3)) & 0x1E));
        buf[(start + 4) >> 4] = ((((_DWORD)num - 6) & 3) << ((2 * (start + 4)) & 0x1E)) | buf[(start + 4) >> 4] & ~(3 << ((2 * (start + 4)) & 0x1E));
      }
      v5 = (2 * alignShift) | 1;
      v6 = &buf[(start + num - 3) >> 4];
      *v6 = (v5 >> 4 << ((2 * (start + num - 3)) & 0x1E)) | *v6 & ~(3 << ((2 * (start + num - 3)) & 0x1E));
      v7 = &buf[(start + num - 2) >> 4];
      *v7 = *v7 & ~(3 << ((2 * (start + num - 2)) & 0x1E)) | (((v5 >> 2) & 3) << ((2 * (start + num - 2)) & 0x1E));
      buf[(start + num - 1) >> 4] = ((v5 & 3) << ((2 * (start + num - 1)) & 0x1E)) | buf[(start + num - 1) >> 4] & ~(3 << ((2 * (start + num - 1)) & 0x1E));
      break;
  }
}

// File Line: 240
// RVA: 0x980110
unsigned __int64 __fastcall Scaleform::Heap::BitSet2::GetBlockSize(const unsigned int *buf, unsigned __int64 start)
{
  unsigned __int64 v2; // rbx
  unsigned int v4; // r9d
  unsigned int v6; // edx
  unsigned int v7; // r9d

  v2 = 2 * start;
  v4 = (buf[start >> 4] >> ((2 * start) & 0x1E)) & 3;
  if ( v4 != 3 )
    return v4;
  v6 = (buf[(start + 1) >> 4] >> ((2 * (start + 1)) & 0x1E)) & 3;
  if ( v6 < 3 )
    return v6 + 3;
  v7 = (buf[(start + 2) >> 4] >> ((2 * (start + 2)) & 0x1E)) & 3;
  if ( v7 == 3 )
    return buf[(v2 + 37) >> 5];
  else
    return ((buf[(start + 4) >> 4] >> ((2 * (start + 4)) & 0x1E)) & 3 | (4
                                                                       * ((4 * v7) | (buf[(start + 3) >> 4] >> ((2 * (start + 3)) & 0x1E)) & 3)))
         + 6;
}

// File Line: 264
// RVA: 0x97FCD0
__int64 __fastcall Scaleform::Heap::BitSet2::GetAlignShift(
        const unsigned int *buf,
        unsigned __int64 start,
        unsigned __int64 num)
{
  if ( num >= 8 )
    return (buf[(start - 1 + num) >> 4] >> ((2 * (start - 1 + num)) & 0x1E) >> 1) & 1 | (2
                                                                                       * ((buf[(start + num - 2) >> 4] >> ((2 * (start + num - 2)) & 0x1E)) & 3 | (4 * ((buf[(start + num - 3) >> 4] >> ((2 * (start + num - 3)) & 0x1E)) & 3))));
  else
    return ((buf[(start + num - 1) >> 4] >> ((2 * (start + num - 1)) & 0x1E)) & 3) - 1;
}

