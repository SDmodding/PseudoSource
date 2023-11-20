// File Line: 473
// RVA: 0x10CCB0
bool __fastcall AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol>>::append(AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol> > *this, ASymbol *elem, unsigned int *insert_pos_p)
{
  unsigned int *v3; // r15
  ASymbol *v4; // rbp
  AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol> > *v5; // r14
  ASymbol *v6; // r11
  unsigned int v7; // er10
  signed __int64 v8; // rbx
  ASymbol *v9; // r9
  ASymbol *v10; // rax
  unsigned int v11; // edx
  _BOOL8 v12; // rcx
  _BOOL8 v13; // rdx
  signed __int64 v14; // rbx
  char v15; // di

  v3 = insert_pos_p;
  v4 = elem;
  v5 = this;
  if ( this->i_count )
  {
    v6 = this->i_array_p;
    v7 = elem->i_uid;
    v8 = (signed __int64)&v6[this->i_count - 1];
    v9 = this->i_array_p;
    while ( 1 )
    {
      while ( 1 )
      {
        v10 = &v9[(v8 - (signed __int64)v9) >> 3];
        v11 = v10->i_uid;
        if ( v7 < v10->i_uid )
          break;
        v12 = v7 == v11;
        v13 = v7 != v11;
        if ( 1 - v12 < 0 )
          break;
        if ( v13 <= 0 )
        {
          v15 = 1;
          LODWORD(v14) = v10 - v6;
          goto LABEL_15;
        }
        if ( (ASymbol *)v8 == v10 )
        {
          v14 = (v8 - (signed __int64)v6 + 4) >> 2;
          goto LABEL_14;
        }
        v9 = v10 + 1;
      }
      if ( v9 == v10 )
        break;
      v8 = (signed __int64)&v10[-1];
    }
    LODWORD(v14) = v10 - v6;
  }
  else
  {
    LODWORD(v14) = 0;
  }
LABEL_14:
  v15 = 0;
LABEL_15:
  AVCompactArrayBase<ASymbol>::insert((AVCompactArrayBase<ASymbol> *)&v5->i_count, v4, v14);
  if ( v3 )
    *v3 = v14;
  return v15 == 0;
}

