// File Line: 99
// RVA: 0x223160
void __fastcall ADatum::ADatum(ADatum *this, const void *data_p, unsigned int data_length, unsigned int size, bool deallocate)
{
  unsigned int v5; // er12
  unsigned int v6; // ebx
  unsigned int *v7; // r14
  ADatum *v8; // rdi
  unsigned int v9; // er15
  UFG::allocator::free_link *v10; // rax
  ADatum::Reference *v11; // rsi
  bool v12; // bp
  char *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rsi
  size_t v16; // r8
  char *v17; // rcx
  ADatum::Reference *v18; // rbx
  unsigned int v19; // ecx

  v5 = size;
  v6 = data_length;
  v7 = (unsigned int *)data_p;
  v8 = this;
  if ( !data_p && data_length == -1 )
    v6 = 0;
  v9 = v6 + 4;
  if ( !size )
  {
    v14 = UFG::qMalloc(0x18ui64, "ADatum::Reference", 0i64);
    if ( v6 == -1 )
    {
      v18 = (ADatum::Reference *)v14;
      if ( v14 )
      {
        v19 = *v7;
        LODWORD(v14->mNext) = 1;
        HIDWORD(v14->mNext) = v19;
        v14[1].mNext = (UFG::allocator::free_link *)ADatum::alloc_buffer(v19);
        v18->i_deallocate = 1;
      }
      else
      {
        v18 = 0i64;
      }
      v8->i_dref_p = v18;
      v16 = v18->i_size;
      v17 = v18->i_buffer_p;
    }
    else
    {
      v15 = v14;
      if ( v14 )
      {
        LODWORD(v14->mNext) = 1;
        HIDWORD(v14->mNext) = v9;
        v14[1].mNext = (UFG::allocator::free_link *)ADatum::alloc_buffer(v9);
        LOBYTE(v15[2].mNext) = 1;
      }
      else
      {
        v15 = 0i64;
      }
      v8->i_dref_p = (ADatum::Reference *)v15;
      v15[1].mNext->mNext = (UFG::allocator::free_link *)v9;
      if ( !v7 )
        return;
      v16 = v6;
      v17 = v8->i_dref_p->i_buffer_p + 4;
    }
    memmove(v17, v7, v16);
    return;
  }
  v10 = UFG::qMalloc(0x18ui64, "ADatum::Reference", 0i64);
  v11 = (ADatum::Reference *)v10;
  if ( v10 )
  {
    v12 = 1;
    LODWORD(v10->mNext) = 1;
    HIDWORD(v10->mNext) = v5;
    if ( v7 )
      v13 = (char *)v7;
    else
      v13 = ADatum::alloc_buffer(v5);
    v11->i_buffer_p = v13;
    if ( v7 )
      v12 = deallocate;
    v11->i_deallocate = v12;
  }
  else
  {
    v11 = 0i64;
  }
  v8->i_dref_p = v11;
  if ( v6 != -1 )
    *(_DWORD *)v11->i_buffer_p = v9;
}

