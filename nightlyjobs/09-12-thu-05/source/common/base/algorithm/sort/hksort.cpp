// File Line: 12
// RVA: 0xC832A0
hkAlgorithm::ListElement *__fastcall hkAlgorithm::_sortList(hkAlgorithm::ListElement *headPtr)
{
  hkAlgorithm::ListElement *v1; // rdx
  signed int i; // er11
  signed int v4; // ebx
  __int64 *v5; // r9
  hkAlgorithm::ListElement *v6; // rax
  signed int j; // ecx
  signed int v8; // er8
  __int64 *v9; // r10
  hkAlgorithm::ListElement *v10; // [rsp+10h] [rbp+8h]

  v1 = headPtr;
  if ( !headPtr )
    return 0i64;
  for ( i = 1; ; i *= 2 )
  {
    v4 = 0;
    v10 = 0i64;
    v5 = (__int64 *)&v10;
    if ( v1 )
    {
      do
      {
        ++v4;
        v6 = v1;
        for ( j = 0; j < i; ++j )
        {
          if ( !v6 )
            break;
          v6 = v6->next;
        }
        v8 = i;
        if ( j > 0 )
        {
          while ( v8 > 0 && v6 )
          {
            if ( v1 > v6 )
            {
              v9 = (__int64 *)v6;
              v6 = v6->next;
              --v8;
            }
            else
            {
              v9 = (__int64 *)v1;
              v1 = v1->next;
              --j;
            }
            *v5 = (__int64)v9;
            v5 = v9;
            if ( j <= 0 )
              goto LABEL_18;
          }
          for ( ; j > 0; v1 = v1->next )
          {
            *v5 = (__int64)v1;
            --j;
            v5 = (__int64 *)v1;
          }
        }
LABEL_18:
        while ( v8 > 0 )
        {
          if ( !v6 )
            break;
          *v5 = (__int64)v6;
          --v8;
          v5 = (__int64 *)v6;
          v6 = v6->next;
        }
        v1 = v6;
      }
      while ( v6 );
    }
    *v5 = 0i64;
    if ( v4 <= 1 )
      break;
    v1 = v10;
  }
  return v10;
}

