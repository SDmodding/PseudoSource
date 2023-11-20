// File Line: 70
// RVA: 0xDFA0B0
void __fastcall hkpMoppDefaultSplitter::hkpMoppMaxList::addElement(hkpMoppDefaultSplitter::hkpMoppMaxList *this, hkpMoppCompilerPrimitive *compPrimitive)
{
  float v2; // xmm0_4
  hkpMoppDefaultSplitter::hkpMoppMaxList *v3; // r10
  int v4; // er9
  signed __int64 v5; // r8
  hkpMoppCompilerPrimitive **v6; // rcx
  hkpMoppCompilerPrimitive *v7; // rax
  hkpMoppCompilerPrimitive **v8; // rcx
  hkpMoppCompilerPrimitive *v9; // rax
  hkpMoppCompilerPrimitive **v10; // rcx
  hkpMoppCompilerPrimitive *v11; // rax
  hkpMoppCompilerPrimitive **v12; // rcx
  hkpMoppCompilerPrimitive *v13; // rax
  hkpMoppCompilerPrimitive **v14; // rcx
  hkpMoppCompilerPrimitive *v15; // rax

  v2 = compPrimitive->m_extent.m_max;
  v3 = this;
  v4 = this->m_currentNumElements - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    if ( v4 + 1i64 < 4 )
    {
LABEL_12:
      while ( v5 >= 0 )
      {
        v14 = v3->buffer;
        v15 = v14[v5];
        if ( !v15 )
          break;
        if ( v2 <= v15->m_extent.m_max )
          break;
        v14[v5 + 1] = v15;
        --v4;
        --v5;
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = v3->buffer;
        v7 = v6[v5];
        if ( !v7 || v2 <= v7->m_extent.m_max )
          break;
        v6[v5 + 1] = v7;
        v8 = v3->buffer;
        v9 = v8[v5 - 1];
        if ( !v9 || v2 <= v9->m_extent.m_max )
        {
          v3->buffer[v4] = compPrimitive;
          ++v3->m_currentNumElements;
          return;
        }
        v8[v5] = v9;
        v10 = v3->buffer;
        v11 = v10[v5 - 2];
        if ( !v11 || v2 <= v11->m_extent.m_max )
        {
          v3->buffer[v4 - 1] = compPrimitive;
          ++v3->m_currentNumElements;
          return;
        }
        v10[v5 - 1] = v11;
        v12 = v3->buffer;
        v13 = v12[v5 - 3];
        if ( !v13 || v2 <= v13->m_extent.m_max )
        {
          v3->buffer[v4 - 2] = compPrimitive;
          ++v3->m_currentNumElements;
          return;
        }
        v12[v5 - 2] = v13;
        v5 -= 4i64;
        v4 -= 4;
        if ( v5 < 3 )
          goto LABEL_12;
      }
    }
  }
  v3->buffer[v4 + 1] = compPrimitive;
  ++v3->m_currentNumElements;
}

// File Line: 113
// RVA: 0xDFA560
void __fastcall hkpMoppDefaultSplitter::hkpMoppMaxList::removeElementsLessThan(hkpMoppDefaultSplitter::hkpMoppMaxList *this, float position)
{
  signed __int64 v2; // rdx
  hkpMoppCompilerPrimitive **v3; // r8
  hkpMoppCompilerPrimitive *v4; // rax
  hkpMoppCompilerPrimitive **v5; // r8
  hkpMoppCompilerPrimitive *v6; // rax
  hkpMoppCompilerPrimitive **v7; // r8
  hkpMoppCompilerPrimitive *v8; // rax
  hkpMoppCompilerPrimitive **v9; // r8
  hkpMoppCompilerPrimitive *v10; // rax
  hkpMoppCompilerPrimitive **v11; // r8
  hkpMoppCompilerPrimitive *v12; // rax

  v2 = this->m_currentNumElements - 1;
  if ( this->m_currentNumElements - 1 >= 0 )
  {
    if ( v2 + 1 < 4 )
    {
LABEL_12:
      while ( v2 >= 0 )
      {
        v11 = this->buffer;
        v12 = v11[v2];
        if ( !v12 )
          break;
        if ( position <= v12->m_extent.m_max )
          break;
        this->lastRemovedElement = v12;
        v11[v2] = 0i64;
        --this->m_currentNumElements;
        --v2;
      }
    }
    else
    {
      while ( 1 )
      {
        v3 = this->buffer;
        v4 = v3[v2];
        if ( !v4 )
          break;
        if ( position <= v4->m_extent.m_max )
          break;
        this->lastRemovedElement = v4;
        v3[v2] = 0i64;
        --this->m_currentNumElements;
        v5 = this->buffer;
        v6 = v5[v2 - 1];
        if ( !v6 )
          break;
        if ( position <= v6->m_extent.m_max )
          break;
        this->lastRemovedElement = v6;
        v5[v2 - 1] = 0i64;
        --this->m_currentNumElements;
        v7 = this->buffer;
        v8 = v7[v2 - 2];
        if ( !v8 )
          break;
        if ( position <= v8->m_extent.m_max )
          break;
        this->lastRemovedElement = v8;
        v7[v2 - 2] = 0i64;
        --this->m_currentNumElements;
        v9 = this->buffer;
        v10 = v9[v2 - 3];
        if ( !v10 || position <= v10->m_extent.m_max )
          break;
        this->lastRemovedElement = v10;
        v9[v2 - 3] = 0i64;
        --this->m_currentNumElements;
        v2 -= 4i64;
        if ( v2 < 3 )
          goto LABEL_12;
      }
    }
  }
}

