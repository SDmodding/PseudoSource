// File Line: 72
// RVA: 0x88260
pugi::xml_node_struct *__fastcall pugi::xml_allocator::allocate<pugi::xml_node_struct,enum  pugi::xml_node_type>(pugi::xml_allocator *this, pugi::xml_node_type val)
{
  char v2; // bl
  pugi::xml_node_struct *result; // rax

  v2 = val;
  result = (pugi::xml_node_struct *)pugi::xml_allocator::memalloc(this, 0x58ui64);
  if ( !result )
    return 0i64;
  *(_DWORD *)result &= 0xFFFFFFF8;
  *(_DWORD *)result |= v2 & 7;
  *((_BYTE *)result + 4) |= 3u;
  *((_DWORD *)result + 2) &= 0xF8000000;
  result->parent = 0i64;
  result->name = 0i64;
  result->value = 0i64;
  result->first_child = 0i64;
  result->last_child = 0i64;
  result->prev_sibling = 0i64;
  result->next_sibling = 0i64;
  result->first_attribute = 0i64;
  result->last_attribute = 0i64;
  return result;
}

// File Line: 89
// RVA: 0x8BB20
char *__fastcall pugi::xml_allocator::memalloc(pugi::xml_allocator *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rdi
  pugi::xml_allocator *v3; // rbx
  pugi::xml_memory_block *v4; // rcx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // r8
  char *result; // rax
  char *v8; // rax
  char *v9; // rcx
  pugi::xml_memory_block *v10; // rcx

  v2 = size;
  v3 = this;
  v4 = this->_root;
  v5 = v4->size;
  v6 = v5 + size;
  if ( v5 + size > 0x8000 )
  {
    v8 = UFG::qMemoryPool::Allocate(v3->_pool, 0x8010ui64, "pugi.xml_memory_block", v3->_alloc, 1u);
    v9 = v8;
    if ( v8 )
    {
      *(_QWORD *)v8 = 0i64;
      *((_QWORD *)v8 + 1) = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    v3->_root->next = (pugi::xml_memory_block *)v9;
    v10 = v3->_root->next;
    v3->_root = v10;
    v10->size = v2;
    result = v3->_root->data;
  }
  else
  {
    result = &v4->data[v5];
    v4->size = v6;
  }
  return result;
}

// File Line: 149
// RVA: 0x8B810
void __fastcall pugi::xml_node_struct::free(pugi::xml_node_struct *this)
{
  pugi::xml_node_struct *v1; // rdi
  pugi::xml_node_struct *i; // rbx
  pugi::xml_attribute_struct *j; // rbx

  v1 = this;
  if ( !(*((_BYTE *)this + 4) & 1) )
    operator delete[](this->name);
  if ( !(*((_BYTE *)v1 + 4) & 2) )
    operator delete[](v1->value);
  for ( i = v1->first_child; i; i = i->next_sibling )
    pugi::xml_node_struct::free(i);
  for ( j = v1->first_attribute; j; j = j->next_attribute )
  {
    if ( !(*(_BYTE *)j & 1) )
      operator delete[](j->name);
    if ( !(*(_BYTE *)j & 2) )
      operator delete[](j->value);
  }
}

// File Line: 161
// RVA: 0x8B610
pugi::xml_node_struct *__fastcall pugi::xml_node_struct::append_node(pugi::xml_node_struct *this, pugi::xml_allocator *alloc, pugi::xml_node_type type)
{
  pugi::xml_node_struct *v3; // rbx
  pugi::xml_node_struct *result; // rax
  pugi::xml_node_struct *v5; // rcx

  v3 = this;
  result = pugi::xml_allocator::allocate<pugi::xml_node_struct,enum  pugi::xml_node_type>(alloc, type);
  result->parent = v3;
  v5 = v3->last_child;
  if ( v5 )
  {
    v5->next_sibling = result;
    result->prev_sibling = v3->last_child;
  }
  else
  {
    v3->first_child = result;
  }
  v3->last_child = result;
  return result;
}

// File Line: 177
// RVA: 0x8B590
pugi::xml_attribute_struct *__fastcall pugi::xml_node_struct::append_attribute(pugi::xml_node_struct *this, pugi::xml_allocator *alloc)
{
  pugi::xml_node_struct *v2; // rbx
  pugi::xml_attribute_struct *result; // rax
  pugi::xml_attribute_struct *v4; // rcx

  v2 = this;
  result = (pugi::xml_attribute_struct *)pugi::xml_allocator::memalloc(alloc, 0x28ui64);
  if ( result )
  {
    *(_BYTE *)result |= 3u;
    *((_DWORD *)result + 1) &= 0xC0000000;
    result->name = 0i64;
    result->value = 0i64;
    result->prev_attribute = 0i64;
    result->next_attribute = 0i64;
  }
  else
  {
    result = 0i64;
  }
  v4 = v2->last_attribute;
  if ( v4 )
  {
    v4->next_attribute = result;
    result->prev_attribute = v2->last_attribute;
  }
  else
  {
    v2->first_attribute = result;
  }
  v2->last_attribute = result;
  return result;
}

// File Line: 322
// RVA: 0x8CBC0
char *__fastcall `anonymous namespace'::strutf16_utf8(char *s, unsigned int ch)
{
  unsigned int v2; // eax
  __int64 v3; // r8
  char *v4; // rcx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  char v8; // al
  char v9; // al
  char v10; // al

  if ( ch < 0x80 )
  {
    v2 = 1;
    goto LABEL_9;
  }
  if ( ch < 0x800 )
  {
    v2 = 2;
    goto LABEL_9;
  }
  if ( ch < 0x10000 )
  {
    v2 = 3;
    goto LABEL_9;
  }
  if ( ch < 0x200000 )
  {
    v2 = 4;
LABEL_9:
    v3 = v2;
    v4 = &s[v2];
    v5 = v2 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( v6 )
      {
        v7 = v6 - 1;
        if ( v7 )
        {
          if ( v7 != 1 )
            return &v4[v3];
          --v4;
          v8 = ch & 0x3F | 0x80;
          ch >>= 6;
          *v4 = v8;
        }
        --v4;
        v9 = ch & 0x3F | 0x80;
        ch >>= 6;
        *v4 = v9;
      }
      --v4;
      v10 = ch & 0x3F | 0x80;
      ch >>= 6;
      *v4 = v10;
    }
    *--v4 = ch | UTF8_FIRST_BYTE_MARK[v3];
    return &v4[v3];
  }
  return s;
}

// File Line: 482
// RVA: 0x8C670
void __fastcall `anonymous namespace'::gap::push(gap *this, char **s, unsigned __int64 count)
{
  char **v3; // rdi
  unsigned __int64 v4; // rsi
  gap *v5; // rbx
  char *v6; // rax

  v3 = s;
  v4 = count;
  v5 = this;
  if ( this->end )
    memmove(&this->end[-this->size], this->end, *s - this->end);
  *v3 += v4;
  v6 = *v3;
  v5->size += v4;
  v5->end = v6;
}

// File Line: 511
// RVA: 0x8C9A0
char *__fastcall `anonymous namespace'::strconv_escape(char *s, gap *g)
{
  char v2; // r8
  char *v3; // rax
  gap *v4; // rsi
  char *v5; // r9
  char *v6; // rbx
  char v7; // cl
  char v9; // al
  unsigned int v10; // edx
  char v11; // cl
  int v12; // edx
  int v13; // eax
  char *v14; // rax
  char *v15; // rbp
  signed __int64 v16; // rdi
  char *sa; // [rsp+30h] [rbp+8h]

  v2 = s[1];
  v3 = s + 1;
  v4 = g;
  v5 = s;
  v6 = s + 1;
  if ( v2 != 35 )
  {
    switch ( v2 )
    {
      case 97:
        v7 = s[2];
        ++v6;
        if ( v7 == 109 )
        {
          if ( *++v6 != 112 )
            return v6;
          if ( *++v6 != 59 )
            return v6;
          *v5 = 38;
        }
        else
        {
          if ( v7 != 112 )
            return v6;
          if ( *++v6 != 111 )
            return v6;
          if ( *++v6 != 115 )
            return v6;
          if ( *++v6 != 59 )
            return v6;
          *v5 = 39;
        }
        break;
      case 103:
        v6 = s + 2;
        if ( s[2] != 116 )
          return v6;
        v6 = s + 3;
        if ( s[3] != 59 )
          return v6;
        *s = 62;
        break;
      case 108:
        v6 = s + 2;
        if ( s[2] != 116 )
          return v6;
        v6 = s + 3;
        if ( s[3] != 59 )
          return v6;
        *s = 60;
        break;
      case 113:
        v6 = s + 2;
        if ( s[2] != 117 )
          return v6;
        v6 = s + 3;
        if ( s[3] != 111 )
          return v6;
        v6 = s + 4;
        if ( s[4] != 116 )
          return v6;
        v6 = s + 5;
        if ( s[5] != 59 )
          return v6;
        *s = 34;
        break;
      default:
        return v6;
    }
    sa = v3;
    `anonymous namespace'::gap::push(g, &sa, v6 + 1 - v3);
    return v6 + 1;
  }
  v9 = s[2];
  v6 = s + 2;
  v10 = 0;
  if ( v9 != 120 )
  {
    if ( v9 >= 48 )
    {
      do
      {
        if ( v9 > 57 )
          break;
        ++v6;
        v10 = v9 + 2 * (5 * v10 - 24);
        v9 = *v6;
      }
      while ( *v6 >= 48 );
    }
LABEL_42:
    if ( *v6 == 59 )
      goto LABEL_43;
    return v6;
  }
  v11 = s[3];
  ++v6;
  if ( !v11 )
    goto LABEL_42;
  while ( (unsigned __int8)(v11 - 48) <= 9u )
  {
    v12 = 16 * v10 - 48;
LABEL_35:
    ++v6;
    v13 = v11;
    v11 = *v6;
    v10 = v13 + v12;
    if ( !*v6 )
      goto LABEL_42;
  }
  if ( (unsigned __int8)(v11 - 65) <= 5u )
  {
    v12 = 16 * v10 - 55;
    goto LABEL_35;
  }
  if ( (unsigned __int8)(v11 - 97) <= 5u )
  {
    v12 = 16 * v10 - 87;
    goto LABEL_35;
  }
  if ( *v6 != 59 )
    return v6;
LABEL_43:
  ++v6;
  v14 = `anonymous namespace'::strutf16_utf8(v5, v10);
  v15 = v14;
  v16 = v6 - v14;
  if ( v4->end )
    memmove(&v4->end[-v4->size], v4->end, v14 - v4->end);
  v4->size += v16;
  v4->end = &v15[v16];
  return v6;
}

// File Line: 629
// RVA: 0x8C8A0
char *__fastcall `anonymous namespace'::strconv_comment(char *s)
{
  char *v1; // rbx
  char *result; // rax
  char *v3; // rdx
  __int64 v4; // rdi
  __int64 v5; // rax
  char v6; // al

  v1 = s;
  if ( !*s )
    return 0i64;
  v3 = 0i64;
  v4 = 0i64;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !(chartype_table[(unsigned __int8)*v1] & 0x20) )
      {
        do
          v5 = (unsigned __int8)(v1++)[1];
        while ( !(chartype_table[v5] & 0x20) );
      }
      v6 = *v1;
      if ( *v1 != 13 )
        break;
      *v1++ = 10;
      if ( *v1 == 10 )
      {
        if ( v3 )
          memmove(&v3[-v4], v3, v1 - v3);
        ++v1;
        ++v4;
        v3 = v1;
      }
    }
    if ( v6 == 45 && v1[1] == 45 && v1[2] == 62 )
      break;
    if ( !v6 )
      return 0i64;
    ++v1;
  }
  if ( v3 )
  {
    memmove(&v3[-v4], v3, v1 - v3);
    v1[-v4] = 0;
    result = v1 + 3;
  }
  else
  {
    result = v1 + 3;
    *v1 = 0;
  }
  return result;
}

// File Line: 659
// RVA: 0x8C7A0
char *__fastcall `anonymous namespace'::strconv_cdata(char *s)
{
  char *v1; // rbx
  char *result; // rax
  char *v3; // rdx
  __int64 v4; // rdi
  __int64 v5; // rax
  char v6; // al

  v1 = s;
  if ( !*s )
    return 0i64;
  v3 = 0i64;
  v4 = 0i64;
  while ( 1 )
  {
    while ( 1 )
    {
      if ( !(chartype_table[(unsigned __int8)*v1] & 0x10) )
      {
        do
          v5 = (unsigned __int8)(v1++)[1];
        while ( !(chartype_table[v5] & 0x10) );
      }
      v6 = *v1;
      if ( *v1 != 13 )
        break;
      *v1++ = 10;
      if ( *v1 == 10 )
      {
        if ( v3 )
          memmove(&v3[-v4], v3, v1 - v3);
        ++v1;
        ++v4;
        v3 = v1;
      }
    }
    if ( v6 == 93 && v1[1] == 93 && v1[2] == 62 )
      break;
    if ( !v6 )
      return 0i64;
    ++v1;
  }
  if ( v3 )
  {
    memmove(&v3[-v4], v3, v1 - v3);
    v1[-v4] = 0;
    result = v1 + 1;
  }
  else
  {
    result = v1 + 1;
    *v1 = 0;
  }
  return result;
}

// File Line: 689
// RVA: 0x89160
char *__fastcall `anonymous namespace'::strconv_pcdata_t<0,1>(char *s)
{
  char *result; // rax
  char *v2; // rbx
  __int64 v3; // rax
  char v4; // al
  gap g; // [rsp+20h] [rbp-18h]

  result = 0i64;
  v2 = s;
  if ( *s )
  {
    g.end = 0i64;
    g.size = 0i64;
    while ( 1 )
    {
      while ( 1 )
      {
        if ( !(chartype_table[(unsigned __int8)*v2] & 1) )
        {
          do
            v3 = (unsigned __int8)(v2++)[1];
          while ( !(chartype_table[v3] & 1) );
        }
        v4 = *v2;
        if ( *v2 != 38 )
          break;
        v2 = `anonymous namespace'::strconv_escape(v2, &g);
      }
      if ( v4 == 60 )
        break;
      if ( !v4 )
        return v2;
      ++v2;
    }
    if ( g.end )
    {
      memmove(&g.end[-g.size], g.end, v2 - g.end);
      v2[-g.size] = 0;
    }
    else
    {
      *v2 = 0;
    }
    result = v2 + 1;
  }
  return result;
}

// File Line: 737
// RVA: 0x882D0
char *__fastcall `anonymous namespace'::strconv_attribute_t<0,1,1,1>(char *s, char end_quote)
{
  char v2; // bp
  char *v3; // rbx
  char *v5; // rdx
  bool v6; // zf
  char *v7; // rsi
  __int64 v8; // rax
  __int64 v9; // rax
  unsigned __int8 v10; // cl
  char *v11; // rax
  __int64 v12; // rax
  signed __int64 v13; // rdi
  __int64 v14; // rax
  signed __int64 v15; // rdi
  _BYTE *v16; // rcx
  __int64 v17; // rax
  gap g; // [rsp+20h] [rbp-18h]

  v2 = end_quote;
  v3 = s;
  if ( !*s )
    return 0i64;
  v5 = 0i64;
  v6 = (chartype_table[(unsigned __int8)*s] & 8) == 0;
  g.end = 0i64;
  v7 = 0i64;
  g.size = 0i64;
  if ( !v6 )
  {
    do
      v8 = (unsigned __int8)(s++)[1];
    while ( chartype_table[v8] & 8 );
    if ( s != v3 )
    {
      v7 = (char *)(s - v3);
      v3 = s;
LABEL_7:
      v5 = v3;
      g.end = v3;
      g.size = (unsigned __int64)v7;
      goto LABEL_8;
    }
  }
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
LABEL_8:
          if ( !(chartype_table[(unsigned __int8)*v3] & 4) )
          {
            do
              v9 = (unsigned __int8)(v3++)[1];
            while ( !(chartype_table[v9] & 4) );
          }
          v10 = *v3;
          if ( *v3 != 38 )
            break;
          v11 = `anonymous namespace'::strconv_escape(v3, &g);
          v7 = (char *)g.size;
          v5 = g.end;
          v3 = v11;
        }
        if ( !(chartype_table[v10] & 8) )
          break;
        *v3 = 32;
        v12 = (unsigned __int8)(v3++)[1];
        if ( chartype_table[v12] & 8 )
        {
          v13 = (signed __int64)(v3 + 1);
          if ( chartype_table[(unsigned __int8)v3[1]] & 8 )
          {
            do
              v14 = *(unsigned __int8 *)(v13++ + 1);
            while ( chartype_table[v14] & 8 );
          }
          v15 = v13 - (_QWORD)v3;
          if ( v5 )
            memmove((void *)(v5 - v7), v5, v3 - v5);
          v3 += v15;
          v7 += v15;
          goto LABEL_7;
        }
      }
      if ( v10 != 13 )
        break;
      *v3++ = 10;
      if ( *v3 == 10 )
      {
        if ( v5 )
          memmove((void *)(v5 - v7), v5, v3 - v5);
        ++v3;
        ++v7;
        goto LABEL_7;
      }
    }
    if ( v10 == v2 )
      break;
    if ( !v10 )
      return 0i64;
    ++v3;
  }
  if ( v5 )
  {
    memmove((void *)(v5 - v7), v5, v3 - v5);
    v16 = (_BYTE *)(v3 - v7);
  }
  else
  {
    v16 = v3;
  }
  do
  {
    *v16 = 0;
    v17 = (unsigned __int8)*(v16-- - 1);
  }
  while ( chartype_table[v17] & 8 );
  return v3 + 1;
}

// File Line: 815
// RVA: 0x8C6E0
char *__fastcall `anonymous namespace'::strconv_attribute(char *s, char end_quote, unsigned int optmask)
{
  char *result; // rax

  switch ( (unsigned __int8)optmask >> 4 )
  {
    case 0:
      result = `anonymous namespace'::strconv_attribute_t<0,0,0,0>(s, end_quote);
      break;
    case 1:
      result = `anonymous namespace'::strconv_attribute_t<0,0,0,1>(s, end_quote);
      break;
    case 2:
      result = `anonymous namespace'::strconv_attribute_t<0,0,1,0>(s, end_quote);
      break;
    case 3:
      result = `anonymous namespace'::strconv_attribute_t<0,0,1,1>(s, end_quote);
      break;
    case 4:
      result = `anonymous namespace'::strconv_attribute_t<1,1,0,0>(s, end_quote);
      break;
    case 5:
      result = `anonymous namespace'::strconv_attribute_t<0,1,0,1>(s, end_quote);
      break;
    case 6:
      result = `anonymous namespace'::strconv_attribute_t<1,1,1,0>(s, end_quote);
      break;
    case 7:
      result = `anonymous namespace'::strconv_attribute_t<0,1,1,1>(s, end_quote);
      break;
    case 8:
      result = `anonymous namespace'::strconv_attribute_t<1,0,0,0>(s, end_quote);
      break;
    case 9:
      result = `anonymous namespace'::strconv_attribute_t<1,0,0,1>(s, end_quote);
      break;
    case 0xA:
      result = `anonymous namespace'::strconv_attribute_t<1,0,1,0>(s, end_quote);
      break;
    case 0xB:
      result = `anonymous namespace'::strconv_attribute_t<1,0,1,1>(s, end_quote);
      break;
    case 0xC:
      result = `anonymous namespace'::strconv_attribute_t<1,1,0,0>(s, end_quote);
      break;
    case 0xD:
      result = `anonymous namespace'::strconv_attribute_t<0,1,0,1>(s, end_quote);
      break;
    case 0xE:
      result = `anonymous namespace'::strconv_attribute_t<1,1,1,0>(s, end_quote);
      break;
    case 0xF:
      result = `anonymous namespace'::strconv_attribute_t<0,1,1,1>(s, end_quote);
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 864
// RVA: 0x8BBD0
char __fastcall `anonymous namespace'::xml_parser::parse(xml_parser *this, char *s, pugi::xml_node_struct *xmldoc, unsigned int optmsk, UFG::qString *error_string, unsigned int *line_count)
{
  unsigned int v6; // er12
  char *v7; // rbx
  xml_parser *v8; // r13
  pugi::xml_node_struct *v9; // r15
  __int64 v10; // rcx
  unsigned int *v11; // rdi
  signed __int64 v12; // rdx
  char *v13; // rbx
  char *v14; // r14
  char *v15; // rbx
  char *v16; // rax
  char *v17; // rsi
  pugi::xml_node_struct *v18; // rax
  char *v19; // rax
  char v20; // al
  unsigned __int8 v21; // cl
  char *v22; // rbx
  __int64 v23; // rax
  char v24; // cl
  char *v25; // rsi
  unsigned __int8 v26; // bp
  char *v27; // rbx
  char v28; // cl
  pugi::xml_node_struct *v29; // rax
  pugi::xml_node_struct *v30; // rdx
  __int64 i; // rcx
  char *v32; // rcx
  unsigned __int8 v33; // al
  char *v34; // rbx
  char *v35; // rbx
  pugi::xml_node_struct *v36; // rsi
  char *v37; // rbx
  bool v38; // zf
  char v39; // al
  char *v40; // rbx
  __int64 j; // rax
  char v42; // cl
  char v43; // cl
  char v44; // al
  signed int v45; // eax
  char v46; // cl
  char v47; // al
  char *v48; // rax
  pugi::xml_node_struct *v49; // rsi
  pugi::xml_node_struct *v50; // rax
  unsigned __int8 v51; // al
  __int64 v52; // rcx
  pugi::xml_attribute_struct *v53; // r8
  unsigned __int8 v54; // dl
  char *v55; // rbx
  __int64 v56; // rcx
  __int64 m; // rax
  char v58; // al
  char *v59; // rbx
  char *v60; // rax
  char v61; // al
  char *v62; // rdx
  unsigned __int8 k; // cl
  char v64; // al
  __int64 l; // rax
  const char *v66; // rcx
  pugi::xml_node_struct *v67; // rax
  const char *v68; // r8
  UFG::qString *v69; // rax
  UFG::qString result; // [rsp+40h] [rbp-68h]
  pugi::xml_node_struct *v72; // [rsp+C0h] [rbp+18h]

  v72 = xmldoc;
  v6 = optmsk;
  v7 = s;
  v8 = this;
  if ( !s || !xmldoc )
    return 0;
  if ( *s == -17 && s[1] == -69 && s[2] == -65 )
    v7 = s + 3;
  v9 = xmldoc;
  LOBYTE(v10) = *v7;
  if ( !*v7 )
    return 1;
  v11 = line_count;
  while ( 1 )
  {
    v12 = 144115188344291361i64;
    if ( (_BYTE)v10 == 60 )
    {
      v13 = v7 + 1;
      goto $LOC_TAG;
    }
    v14 = v7;
    if ( !(chartype_table[(unsigned __int8)v10] & 8) )
      goto LABEL_279;
    do
    {
      if ( (_BYTE)v10 == 10 )
        ++v11;
      v10 = (unsigned __int8)*++v7;
    }
    while ( chartype_table[v10] & 8 );
    if ( v14 == v7 || !(v6 & 8) )
    {
LABEL_279:
      if ( !*v7 )
        goto LABEL_274;
      if ( *v7 == 60 )
        goto LABEL_265;
    }
    v15 = v14;
    if ( (*(_DWORD *)v9 & 7) == 1 )
      break;
    v16 = pugi::xml_allocator::memalloc(v8->alloc, 0x58ui64);
    v17 = v16;
    if ( v16 )
    {
      *(_DWORD *)v16 &= 0xFFFFFFFB;
      *(_DWORD *)v16 |= 3u;
      v16[4] |= 3u;
      *((_DWORD *)v16 + 2) &= 0xF8000000;
      *((_QWORD *)v16 + 2) = 0i64;
      *((_QWORD *)v16 + 3) = 0i64;
      *((_QWORD *)v16 + 4) = 0i64;
      *((_QWORD *)v16 + 5) = 0i64;
      *((_QWORD *)v16 + 6) = 0i64;
      *((_QWORD *)v16 + 7) = 0i64;
      *((_QWORD *)v16 + 8) = 0i64;
      *((_QWORD *)v16 + 9) = 0i64;
      *((_QWORD *)v16 + 10) = 0i64;
    }
    else
    {
      v17 = 0i64;
    }
    *((_QWORD *)v17 + 2) = v9;
    v18 = v9->last_child;
    if ( v18 )
    {
      v18->next_sibling = (pugi::xml_node_struct *)v17;
      *((_QWORD *)v17 + 7) = v9->last_child;
    }
    else
    {
      v9->first_child = (pugi::xml_node_struct *)v17;
    }
    v9->last_child = (pugi::xml_node_struct *)v17;
    *((_QWORD *)v17 + 4) = v14;
    if ( (v6 >> 4) & 3 )
    {
      switch ( (v6 >> 4) & 3 )
      {
        case 1u:
          v19 = `anonymous namespace'::strconv_pcdata_t<0,1>(v14);
          break;
        case 2u:
          v19 = `anonymous namespace'::strconv_pcdata_t<1,0>(v14);
          break;
        case 3u:
          v19 = `anonymous namespace'::strconv_pcdata_t<1,1>(v14);
          break;
        default:
          return 0;
      }
    }
    else
    {
      v19 = `anonymous namespace'::strconv_pcdata_t<0,0>(v14);
    }
    v13 = v19;
    if ( !v19 )
      return 0;
    v9 = (pugi::xml_node_struct *)*((_QWORD *)v17 + 2);
    if ( !*v19 )
      goto LABEL_274;
    v12 = 144115188344291361i64;
$LOC_TAG:
    v21 = *v13;
    if ( *v13 == 63 )
    {
      v22 = v13 + 1;
      v23 = (unsigned __int8)*v22;
      v24 = chartype_table[v23];
      if ( v24 >= 0 )
        return 0;
      if ( !(v6 & 1) )
      {
        while ( 1 )
        {
          switch ( (_BYTE)v23 )
          {
            case 0:
              return 0;
            case 0x3F:
              if ( v22[1] == 62 )
              {
                if ( !*v22 )
                  return 0;
                v7 = v22 + 2;
                goto LABEL_265;
              }
              break;
            case 0xA:
              ++v11;
              break;
          }
          LOBYTE(v23) = *++v22;
        }
      }
      v25 = v22;
      if ( v24 & 0x40 )
      {
        do
        {
          if ( *v22 == 10 )
            ++v11;
          ++v22;
        }
        while ( chartype_table[(unsigned __int8)*v22] & 0x40 );
      }
      v26 = *v22;
      if ( !*v22 || !(chartype_table[v26] & 8) && v26 != 63 )
        return 0;
      *v22 = 0;
      v27 = v22 + 1;
      v28 = *v27;
      if ( !*v27 )
        return 0;
      if ( v26 == 63 )
      {
        if ( v28 != 62 )
          return 0;
        v7 = v27 + 1;
        if ( (*v25 - 88) & 0xDF || (v25[1] - 77) & 0xDF || (v25[2] - 76) & 0xDF || v25[3] )
        {
          v29 = pugi::xml_node_struct::append_node(v9, v8->alloc, node_pi);
          v29->name = v25;
          v9 = v29->parent;
        }
      }
      else
      {
        if ( !((*v25 - 88) & 0xDF) && !((v25[1] - 77) & 0xDF) && !((v25[2] - 76) & 0xDF) && !v25[3] )
        {
          while ( 1 )
          {
            if ( v28 == 63 )
            {
              if ( v27[1] == 62 )
              {
                if ( *v27 )
                {
                  v7 = v27 + 2;
                  goto LABEL_265;
                }
                return 0;
              }
            }
            else if ( v28 == 10 )
            {
              ++v11;
            }
            v28 = *++v27;
            if ( !*v27 )
              return 0;
          }
        }
        v30 = pugi::xml_node_struct::append_node(v9, v8->alloc, node_pi);
        v30->name = v25;
        if ( chartype_table[v26] & 8 )
        {
          for ( i = (unsigned __int8)*v27; chartype_table[i] & 8; i = (unsigned __int8)*v27 )
          {
            if ( (_BYTE)i == 10 )
              ++v11;
            ++v27;
          }
          if ( !*v27 )
            return 0;
          v32 = v27;
        }
        else
        {
          v32 = 0i64;
        }
        if ( !*v27 )
          return 0;
        do
        {
          if ( *v27 == 63 && v27[1] == 62 )
            break;
          if ( *v27 == 10 )
            ++v11;
          ++v27;
        }
        while ( *v27 );
        if ( !*v27 )
          return 0;
        *v27 = 0;
        if ( !v27[1] )
          return 0;
        v7 = v27 + 2;
        v30->value = v32;
        v9 = v30->parent;
      }
      goto LABEL_265;
    }
    if ( v21 == 33 )
    {
      v33 = v13[1];
      if ( v33 != 45 )
      {
        if ( v33 == 91 )
        {
          if ( v13[2] != 67 || v13[3] != 68 || v13[4] != 65 || v13[5] != 84 || v13[6] != 65 || v13[7] != 91 )
            return 0;
          v35 = v13 + 8;
          if ( v6 & 4 )
          {
            v36 = pugi::xml_node_struct::append_node(v9, v8->alloc, node_cdata);
            v36->value = v35;
            if ( v6 & 0x20 )
            {
              v37 = `anonymous namespace'::strconv_cdata(v35);
              v38 = v37 == 0i64;
            }
            else
            {
              if ( !*v35 )
                return 0;
              do
              {
                if ( *v35 == 93 && v35[1] == 93 && v35[2] == 62 )
                  break;
                if ( *v35 == 10 )
                  ++v11;
                ++v35;
              }
              while ( *v35 );
              if ( !*v35 )
                return 0;
              *v35 = 0;
              v37 = v35 + 1;
              v38 = *v37 == 0;
            }
            if ( v38 )
              return 0;
            v9 = v36->parent;
            goto LABEL_155;
          }
          while ( 1 )
          {
            v39 = *v35;
            if ( !*v35 )
              return 0;
            if ( v39 == 93 )
            {
              if ( v35[1] == 93 && v35[2] == 62 )
              {
                if ( !*v35 )
                  return 0;
                v37 = v35 + 1;
LABEL_155:
                v7 = v37 + 2;
                goto LABEL_265;
              }
            }
            else if ( v39 == 10 )
            {
              ++v11;
            }
            ++v35;
          }
        }
        if ( v33 != 68 || v13[2] != 79 || v13[3] != 67 || v13[4] != 84 || v13[5] != 89 || v13[6] != 80 || v13[7] != 69 )
          return 0;
        v40 = v13 + 8;
        for ( j = (unsigned __int8)*v40; chartype_table[j] & 8; j = (unsigned __int8)*v40 )
        {
          if ( (_BYTE)j == 10 )
            ++v11;
          ++v40;
        }
        if ( !*v40 )
          return 0;
        while ( 1 )
        {
          while ( 1 )
          {
            v42 = *v40;
            if ( !*v40 )
              return 0;
            if ( (unsigned __int8)(v42 - 34) <= 0x39u && _bittest64(&v12, (char)(v42 - 34)) )
              break;
            if ( v42 == 10 )
              ++v11;
            ++v40;
          }
          v43 = *v40;
          if ( !*v40 )
            return 0;
          if ( v43 != 39 && v43 != 34 )
          {
            if ( *v40 == 91 )
            {
              v45 = 1;
              do
              {
                v46 = *++v40;
                if ( !*v40 )
                  return 0;
                if ( v46 == 93 )
                {
                  --v45;
                }
                else if ( v46 == 91 )
                {
                  ++v45;
                }
              }
              while ( v45 );
            }
            while ( 1 )
            {
              v47 = *v40;
              if ( !*v40 )
                return 0;
              if ( v47 == 62 )
                break;
              if ( v47 == 10 )
                ++v11;
              ++v40;
            }
            if ( *v40 )
            {
              v7 = v40 + 1;
              goto LABEL_265;
            }
            return 0;
          }
          while ( 1 )
          {
            v44 = *++v40;
            if ( !*v40 )
              return 0;
            if ( v44 == v43 )
              break;
            if ( v44 == 10 )
              ++v11;
          }
          if ( !*v40 )
            return 0;
          ++v40;
        }
      }
      if ( v13[2] != 45 )
        return 0;
      v34 = v13 + 3;
      if ( v6 & 2 )
      {
        v9 = pugi::xml_node_struct::append_node(v9, v8->alloc, node_comment);
        v9->value = v34;
      }
      if ( v6 & 0x20 && v6 & 2 )
      {
        v7 = `anonymous namespace'::strconv_comment(v34);
        if ( !v7 )
          return 0;
      }
      else
      {
        if ( !*v34 )
          return 0;
        do
        {
          if ( *v34 == 45 && v34[1] == 45 && v34[2] == 62 )
            break;
          if ( *v34 == 10 )
            ++v11;
          ++v34;
        }
        while ( *v34 );
        if ( !*v34 )
          return 0;
        if ( v6 & 2 )
          *v34 = 0;
        v7 = v34 + 3;
      }
      if ( v6 & 2 )
        v9 = v9->parent;
    }
    else
    {
      if ( chartype_table[v21] >= 0 )
      {
        if ( v21 != 47 )
          return 0;
        v7 = v13 + 1;
        if ( !v9 )
          return 0;
        v62 = v9->name;
        if ( !v62 )
          return 0;
        for ( k = *v7; *v7; k = *v7 )
        {
          if ( !(chartype_table[k] & 0x40) )
            break;
          v64 = *v62++;
          ++v7;
          if ( k != v64 )
            return 0;
        }
        if ( *v62 )
        {
          if ( error_string )
          {
            v66 = "unknown filename, maybe a generated buffer?";
            if ( v8->_filename )
              v66 = v8->_filename;
            v67 = v9->parent;
            if ( v67 )
              v68 = v67->name;
            else
              v68 = "(no parent node)";
            v69 = UFG::qString::FormatEx(
                    &result,
                    "There is a mis-matching xml tag inside \"%s\".  Potentially a upper / lower case error or a missing "
                    "open / close tag.  Search for the tag \"%s\" in \"%s\"\n",
                    v68,
                    v9->name,
                    v66);
            UFG::qString::Set(error_string, v69->mData, v69->mLength, 0i64, 0);
            UFG::qString::~qString(&result);
          }
          return 0;
        }
        v9 = v9->parent;
        for ( l = (unsigned __int8)*v7; chartype_table[l] & 8; l = (unsigned __int8)*v7 )
        {
          if ( (_BYTE)l == 10 )
            ++v11;
          ++v7;
        }
        v61 = *v7;
        if ( !*v7 )
          return 0;
LABEL_263:
        if ( v61 != 62 )
          return 0;
        ++v7;
        goto LABEL_265;
      }
      v48 = pugi::xml_allocator::memalloc(v8->alloc, 0x58ui64);
      v49 = (pugi::xml_node_struct *)v48;
      if ( v48 )
      {
        *(_DWORD *)v48 &= 0xFFFFFFFA;
        *(_DWORD *)v48 |= 2u;
        v48[4] |= 3u;
        *((_DWORD *)v48 + 2) &= 0xF8000000;
        *((_QWORD *)v48 + 2) = 0i64;
        *((_QWORD *)v48 + 3) = 0i64;
        *((_QWORD *)v48 + 4) = 0i64;
        *((_QWORD *)v48 + 5) = 0i64;
        *((_QWORD *)v48 + 6) = 0i64;
        *((_QWORD *)v48 + 7) = 0i64;
        *((_QWORD *)v48 + 8) = 0i64;
        *((_QWORD *)v48 + 9) = 0i64;
        *((_QWORD *)v48 + 10) = 0i64;
      }
      else
      {
        v49 = 0i64;
      }
      v49->parent = v9;
      v50 = v9->last_child;
      if ( v50 )
      {
        v50->next_sibling = v49;
        v49->prev_sibling = v9->last_child;
      }
      else
      {
        v9->first_child = v49;
      }
      v9->last_child = v49;
      v9 = v49;
      for ( v49->name = v13; chartype_table[(unsigned __int8)*v13] & 0x40; ++v13 )
      {
        if ( *v13 == 10 )
          ++v11;
      }
      v51 = *v13;
      if ( !*v13 )
        return 0;
      *v13 = 0;
      v7 = v13 + 1;
      LOBYTE(v52) = *v7;
      if ( !*v7 )
        return 0;
      if ( v51 == 47 )
      {
        if ( (_BYTE)v52 != 62 )
          return 0;
        v9 = v49->parent;
        ++v7;
      }
      else
      {
        if ( v51 == 62 )
          goto LABEL_265;
        if ( !(chartype_table[v51] & 8) )
          return 0;
        while ( 1 )
        {
          if ( chartype_table[(unsigned __int8)v52] & 8 )
          {
            do
            {
              if ( (_BYTE)v52 == 10 )
                ++v11;
              v52 = (unsigned __int8)*++v7;
            }
            while ( chartype_table[v52] & 8 );
          }
          if ( !*v7 )
            return 0;
          if ( chartype_table[(unsigned __int8)*v7] >= 0 )
            break;
          v53 = pugi::xml_node_struct::append_attribute(v49, v8->alloc);
          for ( v53->name = v7; chartype_table[(unsigned __int8)*v7] & 0x40; ++v7 )
          {
            if ( *v7 == 10 )
              ++v11;
          }
          v54 = *v7;
          if ( !*v7 )
            return 0;
          *v7 = 0;
          v55 = v7 + 1;
          LOBYTE(v56) = *v55;
          if ( !*v55 )
            return 0;
          if ( chartype_table[v54] & 8 )
          {
            if ( chartype_table[(unsigned __int8)v56] & 8 )
            {
              do
              {
                if ( (_BYTE)v56 == 10 )
                  ++v11;
                v56 = (unsigned __int8)*++v55;
              }
              while ( chartype_table[v56] & 8 );
            }
            v54 = *v55;
            if ( !*v55 )
              return 0;
            ++v55;
          }
          if ( v54 != 61 )
            return 0;
          for ( m = (unsigned __int8)*v55; chartype_table[m] & 8; m = (unsigned __int8)*v55 )
          {
            if ( (_BYTE)m == 10 )
              ++v11;
            ++v55;
          }
          v58 = *v55;
          if ( !*v55 || v58 != 39 && v58 != 34 )
            return 0;
          v59 = v55 + 1;
          v53->value = v59;
          v60 = `anonymous namespace'::strconv_attribute(v59, v58, v6);
          v7 = v60;
          if ( !v60 )
            return 0;
          v52 = (unsigned __int8)*v60;
          if ( chartype_table[v52] < 0 )
            return 0;
          if ( !(_BYTE)v52 )
            goto LABEL_274;
        }
        v61 = *v7;
        if ( *v7 != 47 )
          goto LABEL_263;
        if ( v7[1] != 62 )
          return 0;
        v9 = v49->parent;
        v7 += 2;
      }
    }
LABEL_265:
    LOBYTE(v10) = *v7;
    if ( !*v7 )
      goto LABEL_274;
  }
  v20 = *v14;
  if ( *v14 )
  {
    while ( v20 != 60 )
    {
      if ( v20 == 10 )
        ++v11;
      v20 = *++v15;
      if ( !*v15 )
        goto LABEL_274;
    }
  }
  if ( *v15 )
  {
    v13 = v15 + 1;
    goto $LOC_TAG;
  }
LABEL_274:
  if ( v9 != v72 )
    return 0;
  return 1;
}

// File Line: 1685
// RVA: 0x8B890
pugi::xml_node_struct *__fastcall pugi::xml_node::get_allocator(pugi::xml_node *this)
{
  pugi::xml_node_struct *v1; // rax

  v1 = this->_root;
  if ( this->_root )
  {
    while ( v1 && v1->parent )
      v1 = v1->parent;
  }
  return v1 + 1;
}

// File Line: 2448
// RVA: 0x896E0
void __fastcall pugi::xml_document::~xml_document(pugi::xml_document *this)
{
  pugi::xml_document::free(this);
}

// File Line: 2453
// RVA: 0x8B660
void __fastcall pugi::xml_document::create(pugi::xml_document *this)
{
  pugi::xml_document *v1; // rdi
  UFG::qMemoryPool *v2; // rbp
  unsigned __int64 v3; // rsi
  _QWORD *v4; // rbx
  unsigned __int64 v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rax
  char *v8; // rax

  v1 = this;
  v2 = this->_pool;
  v3 = this->_alloc;
  v4 = &this->_memory.next;
  v5 = this->_memory.size;
  v6 = v5 + 112;
  if ( v5 + 112 > 0x8000 )
  {
    v8 = UFG::qMemoryPool::Allocate(v2, 0x8010ui64, "pugi.xml_memory_block", v3, 1u);
    if ( v8 )
    {
      *(_QWORD *)v8 = 0i64;
      *((_QWORD *)v8 + 1) = 0i64;
    }
    else
    {
      v8 = 0i64;
    }
    *v4 = v8;
    v4 = v8;
    *((_QWORD *)v8 + 1) = 112i64;
    v7 = (signed __int64)(v8 + 16);
  }
  else
  {
    v7 = (signed __int64)v4 + v5 + 16;
    v4[1] = v6;
  }
  if ( v7 )
  {
    *(_DWORD *)v7 &= 0xFFFFFFF9;
    *(_DWORD *)v7 |= 1u;
    *(_BYTE *)(v7 + 4) |= 3u;
    *(_DWORD *)(v7 + 8) &= 0xF8000000;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_QWORD *)(v7 + 24) = 0i64;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_QWORD *)(v7 + 40) = 0i64;
    *(_QWORD *)(v7 + 48) = 0i64;
    *(_QWORD *)(v7 + 56) = 0i64;
    *(_QWORD *)(v7 + 64) = 0i64;
    *(_QWORD *)(v7 + 72) = 0i64;
    *(_QWORD *)(v7 + 80) = 0i64;
    *(_QWORD *)(v7 + 88) = 0i64;
    *(_QWORD *)(v7 + 96) = 0i64;
    *(_QWORD *)(v7 + 104) = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  v1->_root = (pugi::xml_node_struct *)v7;
  *(_QWORD *)(v7 + 88) = v4;
  *(_QWORD *)(v7 + 96) = v3;
  *(_QWORD *)(v7 + 104) = v2;
}

// File Line: 2462
// RVA: 0x8B780
void __fastcall pugi::xml_document::free(pugi::xml_document *this)
{
  pugi::xml_document *v1; // rbx
  pugi::xml_node_struct *v2; // rcx
  pugi::xml_memory_block *v3; // rsi
  pugi::xml_memory_block *v4; // rdi
  pugi::xml_allocator *v5; // rax

  v1 = this;
  UFG::qMemoryPool::Free(this->_pool, this->_buffer);
  v2 = v1->_root;
  v1->_buffer = 0i64;
  if ( v2 )
    pugi::xml_node_struct::free(v2);
  v3 = v1->_memory.next;
  if ( v3 )
  {
    do
    {
      v4 = v3->next;
      v5 = pugi::xml_node::get_allocator((pugi::xml_node *)&v1->_root);
      UFG::qMemoryPool::Free(v5->_pool, v3);
      v3 = v4;
    }
    while ( v4 );
  }
  v1->_memory.next = 0i64;
  v1->_memory.size = 0i64;
  pugi::xml_document::create(v1);
}

// File Line: 2523
// RVA: 0x8B8B0
signed __int64 __fastcall pugi::xml_document::load(pugi::xml_document *this, const char *contents, int length, unsigned int options)
{
  unsigned int v4; // ebp
  signed __int64 v5; // rbx
  const char *v6; // rdi
  pugi::xml_document *v7; // r14
  char *v8; // rax
  char *v9; // rsi
  signed __int64 result; // rax
  pugi::xml_node_struct *v11; // r8
  xml_parser v12; // [rsp+30h] [rbp-18h]

  v4 = options;
  LODWORD(v5) = length;
  v6 = contents;
  v7 = this;
  if ( length == -1 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( contents[v5] );
  }
  v8 = UFG::qMemoryPool::Allocate(this->_pool, (signed int)v5 + 1, "pugi.load", 0i64, 1u);
  v9 = v8;
  if ( !v8 )
    return 3i64;
  UFG::qMemCopy(v8, v6, v5);
  v9[(signed int)v5] = 0;
  pugi::xml_document::free(v7);
  v11 = v7->_root;
  v12.alloc = (pugi::xml_allocator *)&v7->_root[1];
  v12._filename = v7->_filename;
  if ( `anonymous namespace'::xml_parser::parse(&v12, v9, v11, v4, 0i64, 0i64) )
  {
    v7->_buffer = v9;
    result = 0i64;
  }
  else
  {
    UFG::qMemoryPool::Free(v7->_pool, v9);
    result = 4i64;
  }
  return result;
}

// File Line: 2554
// RVA: 0x8B9B0
signed __int64 __fastcall pugi::xml_document::load_file(pugi::xml_document *this, const char *name, unsigned int options, UFG::qString *errorString, unsigned int *lineNumber)
{
  pugi::xml_document *v5; // rsi
  UFG::qString *v6; // r15
  unsigned int v7; // er12
  const char *v8; // rbx
  char *v9; // rdi
  UFG::qFile *v10; // rax
  UFG::qFile *v11; // rbp
  signed __int64 result; // rax
  __int64 v13; // rax
  __int64 v14; // r14
  char *v15; // rax
  __int64 v16; // rbx
  pugi::xml_node_struct *v17; // r8
  xml_parser v18; // [rsp+30h] [rbp-28h]

  v5 = this;
  v6 = errorString;
  v7 = options;
  v8 = name;
  v9 = SimpleXML::XMLCache::ExtractFromCache(name);
  if ( !v9 )
  {
    v10 = UFG::qOpen(v8, QACCESS_READ, 1);
    v5->_filename = v8;
    v11 = v10;
    if ( !v10 )
      return 1i64;
    v13 = UFG::qGetFileSize(v10);
    v14 = v13;
    v15 = UFG::qMemoryPool::Allocate(v5->_pool, v13 + 1, "pugi.load", 0i64, 1u);
    v9 = v15;
    if ( !v15 )
    {
      UFG::qClose(v11);
      return (unsigned int)((_DWORD)v9 + 3);
    }
    v16 = UFG::qRead(v11, v15, v14, 0i64, QSEEK_CUR);
    UFG::qClose(v11);
    if ( v16 != v14 )
    {
      UFG::qMemoryPool::Free(v5->_pool, v9);
      return 2i64;
    }
    v9[v14] = 0;
  }
  pugi::xml_document::free(v5);
  v17 = v5->_root;
  v18.alloc = (pugi::xml_allocator *)&v5->_root[1];
  v18._filename = v5->_filename;
  if ( `anonymous namespace'::xml_parser::parse(&v18, v9, v17, v7, v6, lineNumber) )
  {
    v5->_buffer = v9;
    result = 0i64;
  }
  else
  {
    UFG::qMemoryPool::Free(v5->_pool, v9);
    result = 4i64;
  }
  return result;
}

