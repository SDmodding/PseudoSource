// File Line: 31
// RVA: 0x12C59E8
void __fastcall type_info::_Type_info_dtor(type_info *_This)
{
  void *M_data; // rax
  __type_info_node *Next; // rcx
  __type_info_node *v4; // rdx

  lock(14);
  M_data = _This->_M_data;
  if ( M_data )
  {
    Next = _type_info_root_node._Next;
    v4 = &_type_info_root_node;
    while ( _type_info_root_node._Next )
    {
      if ( _type_info_root_node._Next->_MemPtr == M_data )
      {
        v4->_Next = _type_info_root_node._Next->_Next;
        free(Next);
        break;
      }
      v4 = _type_info_root_node._Next;
    }
    free(_This->_M_data);
    _This->_M_data = 0i64;
  }
  unlock(14);
}

// File Line: 72
// RVA: 0x1452191
`type_info::_Type_info_dtor'::`1'::fin$0

