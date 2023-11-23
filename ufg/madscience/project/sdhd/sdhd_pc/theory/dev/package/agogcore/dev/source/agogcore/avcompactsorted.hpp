// File Line: 473
// RVA: 0x10CCB0
bool __fastcall AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol>>::append(
        AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol> > *this,
        ASymbol *elem,
        unsigned int *insert_pos_p)
{
  ASymbol *i_array_p; // r11
  unsigned int i_uid; // r10d
  ASymbol *v8; // rbx
  ASymbol *v9; // r9
  char *v10; // rax
  int v11; // edx
  _BOOL8 v12; // rcx
  _BOOL8 v13; // rdx
  __int64 v14; // rbx
  char v15; // di

  if ( this->i_count )
  {
    i_array_p = this->i_array_p;
    i_uid = elem->i_uid;
    v8 = &i_array_p[this->i_count - 1];
    v9 = i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = (char *)&v9[((char *)v8 - (char *)v9) >> 3];
        v11 = *(_DWORD *)v10;
        if ( i_uid < *(_DWORD *)v10 )
          break;
        v12 = i_uid == v11;
        v13 = i_uid != v11;
        if ( 1 - v12 < 0 )
          break;
        if ( v13 <= 0 )
        {
          v15 = 1;
          LODWORD(v14) = (v10 - (char *)i_array_p) >> 2;
          goto LABEL_15;
        }
        if ( v8 == (ASymbol *)v10 )
        {
          v14 = ((char *)v8 - (char *)i_array_p + 4) >> 2;
          goto LABEL_14;
        }
        v9 = (ASymbol *)(v10 + 4);
      }
      if ( v9 == (ASymbol *)v10 )
        break;
      v8 = (ASymbol *)(v10 - 4);
    }
    LODWORD(v14) = (v10 - (char *)i_array_p) >> 2;
  }
  else
  {
    LODWORD(v14) = 0;
  }
LABEL_14:
  v15 = 0;
LABEL_15:
  AVCompactArrayBase<ASymbol>::insert(this, elem, v14);
  if ( insert_pos_p )
    *insert_pos_p = v14;
  return v15 == 0;
}

