// File Line: 123
// RVA: 0x223750
bool __fastcall AMemoryInfo::operator==(AMemoryInfo *this, AMemoryInfo *rhs)
{
  unsigned int v4; // ebx

  if ( AMemoryInfo::c_sort_type == SortType_id )
    return this->i_type_id == rhs->i_type_id;
  v4 = this->i_size_dynamic_total_actual + this->i_alloc_count * AMemory::c_req_byte_size_func(this->i_size_static);
  return v4 == rhs->i_size_dynamic_total_actual + AMemory::c_req_byte_size_func(rhs->i_size_static) * rhs->i_alloc_count
      && this->i_alloc_count == rhs->i_alloc_count;
}

// File Line: 358
// RVA: 0x226C50
void __fastcall AMemoryStats::track_memory(
        AMemoryStats *this,
        const char *type_cstr_p,
        unsigned int size_sizeof,
        unsigned int size_debug,
        unsigned int size_dynamic_needed,
        unsigned int size_dynamic,
        unsigned int alloc_count)
{
  const char *v9; // rsi
  unsigned int v11; // r13d
  unsigned int v12; // edi
  __int64 v13; // rax
  const char *i; // r8
  AMemoryInfoList *i_info_list_p; // rbx
  AMemoryInfo *v16; // rbx
  UFG::allocator::free_link *v17; // rax
  AMemoryInfo key; // [rsp+38h] [rbp-50h] BYREF

  v9 = type_cstr_p;
  v11 = alloc_count;
  if ( this->i_track == Track_type )
  {
    v12 = -1;
    v13 = -1i64;
    do
      ++v13;
    while ( type_cstr_p[v13] );
    for ( i = &type_cstr_p[(unsigned int)v13]; type_cstr_p < i; ++type_cstr_p )
      v12 = (v12 << 8) ^ g_table_crc32[(unsigned __int8)(*type_cstr_p ^ HIBYTE(v12))];
    key.i_type_id = v12;
    i_info_list_p = this->i_info_list_p;
    if ( APSorted<AMemoryInfo,AMemoryInfo,ACompareLogicalReverse<AMemoryInfo>>::find(
           i_info_list_p,
           &key,
           0,
           &alloc_count,
           0,
           0xFFFFFFFF) )
    {
      v16 = i_info_list_p->i_array_p[alloc_count];
    }
    else
    {
      v16 = 0i64;
    }
    if ( !v16 )
    {
      v17 = UFG::qMalloc(0x20ui64, UFG::gGlobalNewName, 0i64);
      v16 = (AMemoryInfo *)v17;
      if ( v17 )
      {
        v17->mNext = (UFG::allocator::free_link *)v9;
        LODWORD(v17[1].mNext) = v12;
        HIDWORD(v17[1].mNext) = size_sizeof;
        LODWORD(v17[2].mNext) = size_debug;
        *(UFG::allocator::free_link **)((char *)&v17[2].mNext + 4) = 0i64;
        HIDWORD(v17[3].mNext) = 0;
      }
      else
      {
        v16 = 0i64;
      }
      APSizedArrayBase<AMemoryInfo>::insert(this->i_info_list_p, v16, alloc_count);
    }
    v16->i_size_dynamic_total += size_dynamic;
    v16->i_size_dynamic_total_actual += AMemory::c_req_byte_size_func(size_dynamic);
    v16->i_alloc_count += v11;
  }
  this->i_size_needed += size_dynamic_needed + v11 * size_sizeof;
  this->i_size_needed_debug += v11 * size_debug;
}

// File Line: 456
// RVA: 0x222F60
__int64 __fastcall AMemory::request_byte_size_default(unsigned int bytes_requested)
{
  return bytes_requested;
}

// File Line: 466
// RVA: 0x2263E0
void __fastcall AMemory::override_functions(
        void *(__fastcall *malloc_func)(unsigned __int64, const char *),
        void (__fastcall *free_func)(void *),
        unsigned int (__fastcall *req_byte_size_func)(unsigned int))
{
  AMemory::c_malloc_func = malloc_func;
  AMemory::c_free_func = free_func;
  AMemory::c_req_byte_size_func = req_byte_size_func;
}

