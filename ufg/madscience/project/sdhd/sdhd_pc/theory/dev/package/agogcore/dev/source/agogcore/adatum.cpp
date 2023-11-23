// File Line: 99
// RVA: 0x223160
void __fastcall ADatum::ADatum(
        ADatum *this,
        unsigned int *data_p,
        unsigned int data_length,
        unsigned int size,
        bool deallocate)
{
  unsigned int v6; // ebx
  unsigned int v9; // r15d
  UFG::allocator::free_link *v10; // rax
  ADatum::Reference *v11; // rsi
  bool v12; // bp
  char *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rsi
  size_t i_size; // r8
  char *i_buffer_p; // rcx
  ADatum::Reference *v18; // rbx
  unsigned int v19; // ecx

  v6 = data_length;
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
        v19 = *data_p;
        LODWORD(v14->mNext) = 1;
        HIDWORD(v14->mNext) = v19;
        v14[1].mNext = (UFG::allocator::free_link *)ADatum::alloc_buffer(v19);
        v18->i_deallocate = 1;
      }
      else
      {
        v18 = 0i64;
      }
      this->i_dref_p = v18;
      i_size = v18->i_size;
      i_buffer_p = v18->i_buffer_p;
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
      this->i_dref_p = (ADatum::Reference *)v15;
      LODWORD(v15[1].mNext->mNext) = v9;
      if ( !data_p )
        return;
      i_size = v6;
      i_buffer_p = this->i_dref_p->i_buffer_p + 4;
    }
    memmove(i_buffer_p, data_p, i_size);
    return;
  }
  v10 = UFG::qMalloc(0x18ui64, "ADatum::Reference", 0i64);
  v11 = (ADatum::Reference *)v10;
  if ( v10 )
  {
    v12 = 1;
    LODWORD(v10->mNext) = 1;
    HIDWORD(v10->mNext) = size;
    if ( data_p )
      v13 = (char *)data_p;
    else
      v13 = ADatum::alloc_buffer(size);
    v11->i_buffer_p = v13;
    if ( data_p )
      v12 = deallocate;
    v11->i_deallocate = v12;
  }
  else
  {
    v11 = 0i64;
  }
  this->i_dref_p = v11;
  if ( v6 != -1 )
    *(_DWORD *)v11->i_buffer_p = v9;
}

