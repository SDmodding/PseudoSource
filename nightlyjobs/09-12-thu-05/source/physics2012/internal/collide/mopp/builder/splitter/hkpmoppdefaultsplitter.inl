// File Line: 70
// RVA: 0xDFA0B0
void __fastcall hkpMoppDefaultSplitter::hkpMoppMaxList::addElement(
        hkpMoppDefaultSplitter::hkpMoppMaxList *this,
        hkpMoppCompilerPrimitive *compPrimitive)
{
  float m_max; // xmm0_4
  int v4; // r9d
  __int64 v5; // r8
  hkpMoppCompilerPrimitive **v6; // rcx
  hkpMoppCompilerPrimitive *v7; // rax
  hkpMoppCompilerPrimitive **v8; // rcx
  hkpMoppCompilerPrimitive *v9; // rax
  hkpMoppCompilerPrimitive **v10; // rcx
  hkpMoppCompilerPrimitive *v11; // rax
  hkpMoppCompilerPrimitive **v12; // rcx
  hkpMoppCompilerPrimitive *v13; // rax
  hkpMoppCompilerPrimitive **buffer; // rcx
  hkpMoppCompilerPrimitive *v15; // rax

  m_max = compPrimitive->m_extent.m_max;
  v4 = this->m_currentNumElements - 1;
  v5 = v4;
  if ( v4 >= 0 )
  {
    if ( v4 + 1i64 < 4 )
    {
LABEL_12:
      while ( v5 >= 0 )
      {
        buffer = this->buffer;
        v15 = buffer[v5];
        if ( !v15 )
          break;
        if ( m_max <= v15->m_extent.m_max )
          break;
        buffer[v5 + 1] = v15;
        --v4;
        --v5;
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = this->buffer;
        v7 = v6[v5];
        if ( !v7 || m_max <= v7->m_extent.m_max )
          break;
        v6[v5 + 1] = v7;
        v8 = this->buffer;
        v9 = v8[v5 - 1];
        if ( !v9 || m_max <= v9->m_extent.m_max )
        {
          this->buffer[v4] = compPrimitive;
          ++this->m_currentNumElements;
          return;
        }
        v8[v5] = v9;
        v10 = this->buffer;
        v11 = v10[v5 - 2];
        if ( !v11 || m_max <= v11->m_extent.m_max )
        {
          this->buffer[v4 - 1] = compPrimitive;
          ++this->m_currentNumElements;
          return;
        }
        v10[v5 - 1] = v11;
        v12 = this->buffer;
        v13 = v12[v5 - 3];
        if ( !v13 || m_max <= v13->m_extent.m_max )
        {
          this->buffer[v4 - 2] = compPrimitive;
          ++this->m_currentNumElements;
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
  this->buffer[v4 + 1] = compPrimitive;
  ++this->m_currentNumElements;
}

// File Line: 113
// RVA: 0xDFA560
void __fastcall hkpMoppDefaultSplitter::hkpMoppMaxList::removeElementsLessThan(
        hkpMoppDefaultSplitter::hkpMoppMaxList *this,
        float position)
{
  __int64 v2; // rdx
  hkpMoppCompilerPrimitive **v3; // r8
  hkpMoppCompilerPrimitive *v4; // rax
  hkpMoppCompilerPrimitive **v5; // r8
  hkpMoppCompilerPrimitive *v6; // rax
  hkpMoppCompilerPrimitive **v7; // r8
  hkpMoppCompilerPrimitive *v8; // rax
  hkpMoppCompilerPrimitive **v9; // r8
  hkpMoppCompilerPrimitive *v10; // rax
  hkpMoppCompilerPrimitive **buffer; // r8
  hkpMoppCompilerPrimitive *v12; // rax

  v2 = this->m_currentNumElements - 1;
  if ( this->m_currentNumElements - 1 >= 0 )
  {
    if ( v2 + 1 < 4 )
    {
LABEL_12:
      while ( v2 >= 0 )
      {
        buffer = this->buffer;
        v12 = buffer[v2];
        if ( !v12 )
          break;
        if ( position <= v12->m_extent.m_max )
          break;
        this->lastRemovedElement = v12;
        buffer[v2] = 0i64;
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

