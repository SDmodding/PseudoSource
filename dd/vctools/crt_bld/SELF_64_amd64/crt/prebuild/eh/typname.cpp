// File Line: 31
// RVA: 0x12C59E8
void __fastcall type_info::_Type_info_dtor(type_info *_This)
{
  type_info *v1; // rbx
  void *v2; // rax
  __type_info_node *v3; // rcx
  __type_info_node *v4; // rdx

  v1 = _This;
  lock(14);
  v2 = v1->_M_data;
  if ( v2 )
  {
    v3 = _type_info_root_node._Next;
    v4 = &_type_info_root_node;
    while ( _type_info_root_node._Next )
    {
      if ( _type_info_root_node._Next->_MemPtr == v2 )
      {
        v4->_Next = _type_info_root_node._Next->_Next;
        free(v3);
        break;
      }
      v4 = _type_info_root_node._Next;
    }
    free(v1->_M_data);
    v1->_M_data = 0i64;
  }
  unlock(14);
}

// File Line: 72
// RVA: 0x1452191
`type_info::_Type_info_dtor'::`1'::fin$0

