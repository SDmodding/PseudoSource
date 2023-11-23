// File Line: 72
// RVA: 0x88260
pugi::xml_node_struct *__fastcall pugi::xml_allocator::allocate<pugi::xml_node_struct,enum pugi::xml_node_type>(
        pugi::xml_allocator *this,
        pugi::xml_node_type val)
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
  pugi::xml_memory_block *root; // rcx
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // r8
  char *result; // rax
  char *v8; // rax
  pugi::xml_memory_block *v9; // rcx
  pugi::xml_memory_block *next; // rcx

  root = this->_root;
  v5 = root->size;
  v6 = v5 + size;
  if ( v5 + size > 0x8000 )
  {
    v8 = UFG::qMemoryPool::Allocate(this->_pool, 0x8010ui64, "pugi.xml_memory_block", this->_alloc, 1u);
    v9 = (pugi::xml_memory_block *)v8;
    if ( v8 )
    {
      *(_QWORD *)v8 = 0i64;
      *((_QWORD *)v8 + 1) = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    this->_root->next = v9;
    next = this->_root->next;
    this->_root = next;
    next->size = size;
    return this->_root->data;
  }
  else
  {
    result = &root->data[v5];
    root->size = v6;
  }
  return result;
}

// File Line: 149
// RVA: 0x8B810
void __fastcall pugi::xml_node_struct::free(pugi::xml_node_struct *this)
{
  pugi::xml_node_struct *i; // rbx
  pugi::xml_attribute_struct *j; // rbx

  if ( (*((_BYTE *)this + 4) & 1) == 0 )
    operator delete[](this->name);
  if ( (*((_BYTE *)this + 4) & 2) == 0 )
    operator delete[](this->value);
  for ( i = this->first_child; i; i = i->next_sibling )
    pugi::xml_node_struct::free(i);
  for ( j = this->first_attribute; j; j = j->next_attribute )
  {
    if ( (*(_BYTE *)j & 1) == 0 )
      operator delete[](j->name);
    if ( (*(_BYTE *)j & 2) == 0 )
      operator delete[](j->value);
  }
}

// File Line: 161
// RVA: 0x8B610
pugi::xml_node_struct *__fastcall pugi::xml_node_struct::append_node(
        pugi::xml_node_struct *this,
        pugi::xml_allocator *alloc,
        pugi::xml_node_type type)
{
  pugi::xml_node_struct *result; // rax
  pugi::xml_node_struct *last_child; // rcx

  result = pugi::xml_allocator::allocate<pugi::xml_node_struct,enum pugi::xml_node_type>(alloc, type);
  result->parent = this;
  last_child = this->last_child;
  if ( last_child )
  {
    last_child->next_sibling = result;
    result->prev_sibling = this->last_child;
  }
  else
  {
    this->first_child = result;
  }
  this->last_child = result;
  return result;
}

// File Line: 177
// RVA: 0x8B590
pugi::xml_attribute_struct *__fastcall pugi::xml_node_struct::append_attribute(
        pugi::xml_node_struct *this,
        pugi::xml_allocator *alloc)
{
  pugi::xml_attribute_struct *result; // rax
  pugi::xml_attribute_struct *last_attribute; // rcx

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
  last_attribute = this->last_attribute;
  if ( last_attribute )
  {
    last_attribute->next_attribute = result;
    result->prev_attribute = this->last_attribute;
  }
  else
  {
    this->first_attribute = result;
  }
  this->last_attribute = result;
  return result;
}

// File Line: 322
// RVA: 0x8CBC0
char *__fastcall `anonymous namespace::strutf16_utf8(char *s, unsigned int ch)
{
  unsigned int v2; // eax
  __int64 v3; // r8
  char *v4; // rcx
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
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
void __fastcall `anonymous namespace::gap::push(gap *this, char **s, unsigned __int64 count)
{
  char *v6; // rax

  if ( this->end )
    memmove(&this->end[-this->size], this->end, *s - this->end);
  *s += count;
  v6 = *s;
  this->size += count;
  this->end = v6;
}

// File Line: 511
// RVA: 0x8C9A0
char *__fastcall `anonymous namespace::strconv_escape(char *s, gap *g)
{
  char v2; // r8
  char *v3; // rax
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
  char *sa; // [rsp+30h] [rbp+8h] BYREF

  v2 = s[1];
  v3 = s + 1;
  v6 = s + 1;
  if ( v2 != 35 )
  {
    switch ( v2 )
    {
      case a:
        v7 = s[2];
        ++v6;
        if ( v7 == 109 )
        {
          if ( *++v6 != 112 )
            return v6;
          if ( *++v6 != 59 )
            return v6;
          *s = 38;
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
          *s = 39;
        }
        break;
      case g:
        v6 = s + 2;
        if ( s[2] != 116 )
          return v6;
        v6 = s + 3;
        if ( s[3] != 59 )
          return v6;
        *s = 62;
        break;
      case l:
        v6 = s + 2;
        if ( s[2] != 116 )
          return v6;
        v6 = s + 3;
        if ( s[3] != 59 )
          return v6;
        *s = 60;
        break;
      case q:
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
    `anonymous namespace::gap::push(g, &sa, v6 + 1 - v3);
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
  v14 = `anonymous namespace::strutf16_utf8(s, v10);
  v15 = v14;
  v16 = v6 - v14;
  if ( g->end )
    memmove(&g->end[-g->size], g->end, v14 - g->end);
  g->size += v16;
  g->end = &v15[v16];
  return v6;
}

// File Line: 629
// RVA: 0x8C8A0
char *__fastcall `anonymous namespace::strconv_comment(char *s)
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
      if ( (chartype_table[(unsigned __int8)*v1] & 0x20) == 0 )
      {
        do
          v5 = (unsigned __int8)*++v1;
        while ( (chartype_table[v5] & 0x20) == 0 );
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
    return v1 + 3;
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
char *__fastcall `anonymous namespace::strconv_cdata(char *s)
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
      if ( (chartype_table[(unsigned __int8)*v1] & 0x10) == 0 )
      {
        do
          v5 = (unsigned __int8)*++v1;
        while ( (chartype_table[v5] & 0x10) == 0 );
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
    return v1 + 1;
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
char *__fastcall `anonymous namespace::strconv_pcdata_t<0,1>(char *s)
{
  char *result; // rax
  char *v2; // rbx
  __int64 v3; // rax
  char v4; // al
  gap g; // [rsp+20h] [rbp-18h] BYREF

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
        if ( (chartype_table[(unsigned __int8)*v2] & 1) == 0 )
        {
          do
            v3 = (unsigned __int8)*++v2;
          while ( (chartype_table[v3] & 1) == 0 );
        }
        v4 = *v2;
        if ( *v2 != 38 )
          break;
        v2 = `anonymous namespace::strconv_escape(v2, &g);
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
    return v2 + 1;
  }
  return result;
}

// File Line: 737
// RVA: 0x882D0
char *__fastcall `anonymous namespace::strconv_attribute_t<0,1,1,1>(char *s, char end_quote)
{
  char *v3; // rbx
  char *end; // rdx
  bool v6; // zf
  char *size; // rsi
  __int64 v8; // rax
  __int64 v9; // rax
  unsigned __int8 v10; // cl
  char *v11; // rax
  __int64 v12; // rax
  char *v13; // rdi
  __int64 v14; // rax
  __int64 v15; // rdi
  _BYTE *v16; // rcx
  __int64 v17; // rax
  gap g; // [rsp+20h] [rbp-18h] BYREF

  v3 = s;
  if ( !*s )
    return 0i64;
  end = 0i64;
  v6 = (chartype_table[(unsigned __int8)*s] & 8) == 0;
  g.end = 0i64;
  size = 0i64;
  g.size = 0i64;
  if ( !v6 )
  {
    do
      v8 = (unsigned __int8)*++s;
    while ( (chartype_table[v8] & 8) != 0 );
    if ( s != v3 )
    {
      size = (char *)(s - v3);
      v3 = s;
LABEL_7:
      end = v3;
      g.end = v3;
      g.size = (unsigned __int64)size;
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
          if ( (chartype_table[(unsigned __int8)*v3] & 4) == 0 )
          {
            do
              v9 = (unsigned __int8)*++v3;
            while ( (chartype_table[v9] & 4) == 0 );
          }
          v10 = *v3;
          if ( *v3 != 38 )
            break;
          v11 = `anonymous namespace::strconv_escape(v3, &g);
          size = (char *)g.size;
          end = g.end;
          v3 = v11;
        }
        if ( (chartype_table[v10] & 8) == 0 )
          break;
        *v3 = 32;
        v12 = (unsigned __int8)*++v3;
        if ( (chartype_table[v12] & 8) != 0 )
        {
          v13 = v3 + 1;
          if ( (chartype_table[(unsigned __int8)v3[1]] & 8) != 0 )
          {
            do
              v14 = (unsigned __int8)*++v13;
            while ( (chartype_table[v14] & 8) != 0 );
          }
          v15 = v13 - v3;
          if ( end )
            memmove((void *)(end - size), end, v3 - end);
          v3 += v15;
          size += v15;
          goto LABEL_7;
        }
      }
      if ( v10 != 13 )
        break;
      *v3++ = 10;
      if ( *v3 == 10 )
      {
        if ( end )
          memmove((void *)(end - size), end, v3 - end);
        ++v3;
        ++size;
        goto LABEL_7;
      }
    }
    if ( v10 == end_quote )
      break;
    if ( !v10 )
      return 0i64;
    ++v3;
  }
  if ( end )
  {
    memmove((void *)(end - size), end, v3 - end);
    v16 = (_BYTE *)(v3 - size);
  }
  else
  {
    v16 = v3;
  }
  do
  {
    *v16 = 0;
    v17 = (unsigned __int8)*--v16;
  }
  while ( (chartype_table[v17] & 8) != 0 );
  return v3 + 1;
}

// File Line: 815
// RVA: 0x8C6E0
char *__fastcall `anonymous namespace::strconv_attribute(char *s, char end_quote, unsigned __int8 optmask)
{
  char *result; // rax

  switch ( optmask >> 4 )
  {
    case 0:
      result = `anonymous namespace::strconv_attribute_t<0,0,0,0>(s, end_quote);
      break;
    case 1:
      result = `anonymous namespace::strconv_attribute_t<0,0,0,1>(s, end_quote);
      break;
    case 2:
      result = `anonymous namespace::strconv_attribute_t<0,0,1,0>(s, end_quote);
      break;
    case 3:
      result = `anonymous namespace::strconv_attribute_t<0,0,1,1>(s, end_quote);
      break;
    case 4:
    case 12:
      result = `anonymous namespace::strconv_attribute_t<1,1,0,0>(s, end_quote);
      break;
    case 5:
    case 13:
      result = `anonymous namespace::strconv_attribute_t<0,1,0,1>(s, end_quote);
      break;
    case 6:
    case 14:
      result = `anonymous namespace::strconv_attribute_t<1,1,1,0>(s, end_quote);
      break;
    case 7:
    case 15:
      result = `anonymous namespace::strconv_attribute_t<0,1,1,1>(s, end_quote);
      break;
    case 8:
      result = `anonymous namespace::strconv_attribute_t<1,0,0,0>(s, end_quote);
      break;
    case 9:
      result = `anonymous namespace::strconv_attribute_t<1,0,0,1>(s, end_quote);
      break;
    case 10:
      result = `anonymous namespace::strconv_attribute_t<1,0,1,0>(s, end_quote);
      break;
    case 11:
      result = `anonymous namespace::strconv_attribute_t<1,0,1,1>(s, end_quote);
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

// File Line: 864
// RVA: 0x8BBD0
char __fastcall `anonymous namespace::xml_parser::parse(
        xml_parser *this,
        char *s,
        pugi::xml_node_struct *xmldoc,
        unsigned int optmsk,
        UFG::qString *error_string,
        unsigned int *line_count)
{
  char *v7; // rbx
  pugi::xml_node_struct *parent; // r15
  __int64 v10; // rcx
  __int64 v12; // rdx
  char *v13; // rbx
  char *v14; // r14
  char *v15; // rbx
  char *v16; // rax
  char *v17; // rsi
  pugi::xml_node_struct *last_child; // rax
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
  pugi::xml_node_struct *appended; // rax
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
  int v45; // eax
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
  __int64 n; // rax
  char v58; // al
  char *v59; // rbx
  char *v60; // rax
  char v61; // al
  char *name; // rdx
  unsigned __int8 k; // cl
  char v64; // al
  __int64 m; // rax
  const char *filename; // rcx
  pugi::xml_node_struct *v67; // rax
  const char *v68; // r8
  UFG::qString *v69; // rax
  UFG::qString result; // [rsp+40h] [rbp-68h] BYREF

  v7 = s;
  if ( !s || !xmldoc )
    return 0;
  if ( *s == -17 && s[1] == -69 && s[2] == -65 )
    v7 = s + 3;
  parent = xmldoc;
  LOBYTE(v10) = *v7;
  if ( !*v7 )
    return 1;
  while ( 1 )
  {
    v12 = 0x200000010000021i64;
    if ( (_BYTE)v10 == 60 )
    {
      v13 = v7 + 1;
      goto $LOC_TAG;
    }
    v14 = v7;
    if ( (chartype_table[(unsigned __int8)v10] & 8) == 0 )
      goto LABEL_16;
    do
    {
      if ( (_BYTE)v10 == 10 )
        ++line_count;
      v10 = (unsigned __int8)*++v7;
    }
    while ( (chartype_table[v10] & 8) != 0 );
    if ( v14 == v7 || (optmsk & 8) == 0 )
    {
LABEL_16:
      if ( !*v7 )
        return parent == xmldoc;
      if ( *v7 == 60 )
        goto LABEL_261;
    }
    v15 = v14;
    if ( (*(_DWORD *)parent & 7) == 1 )
      break;
    v16 = pugi::xml_allocator::memalloc(this->alloc, 0x58ui64);
    v17 = v16;
    if ( v16 )
    {
      *(_DWORD *)v16 &= ~4u;
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
    *((_QWORD *)v17 + 2) = parent;
    last_child = parent->last_child;
    if ( last_child )
    {
      last_child->next_sibling = (pugi::xml_node_struct *)v17;
      *((_QWORD *)v17 + 7) = parent->last_child;
    }
    else
    {
      parent->first_child = (pugi::xml_node_struct *)v17;
    }
    parent->last_child = (pugi::xml_node_struct *)v17;
    *((_QWORD *)v17 + 4) = v14;
    if ( ((optmsk >> 4) & 3) != 0 )
    {
      switch ( (optmsk >> 4) & 3 )
      {
        case 1u:
          v19 = `anonymous namespace::strconv_pcdata_t<0,1>(v14);
          break;
        case 2u:
          v19 = `anonymous namespace::strconv_pcdata_t<1,0>(v14);
          break;
        case 3u:
          v19 = `anonymous namespace::strconv_pcdata_t<1,1>(v14);
          break;
        default:
          return 0;
      }
    }
    else
    {
      v19 = `anonymous namespace::strconv_pcdata_t<0,0>(v14);
    }
    v13 = v19;
    if ( !v19 )
      return 0;
    parent = (pugi::xml_node_struct *)*((_QWORD *)v17 + 2);
    if ( !*v19 )
      return parent == xmldoc;
    v12 = 0x200000010000021i64;
$LOC_TAG:
    v21 = *v13;
    if ( *v13 == 63 )
    {
      v22 = v13 + 1;
      v23 = (unsigned __int8)*v22;
      v24 = chartype_table[v23];
      if ( v24 >= 0 )
        return 0;
      if ( (optmsk & 1) == 0 )
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
                goto LABEL_261;
              }
              break;
            case 0xA:
              ++line_count;
              break;
          }
          LOBYTE(v23) = *++v22;
        }
      }
      v25 = v22;
      if ( (v24 & 0x40) != 0 )
      {
        do
        {
          if ( *v22 == 10 )
            ++line_count;
          ++v22;
        }
        while ( (chartype_table[(unsigned __int8)*v22] & 0x40) != 0 );
      }
      v26 = *v22;
      if ( !*v22 || (chartype_table[v26] & 8) == 0 && v26 != 63 )
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
        if ( ((*v25 - 88) & 0xDF) != 0 || ((v25[1] - 77) & 0xDF) != 0 || ((v25[2] - 76) & 0xDF) != 0 || v25[3] )
        {
          appended = pugi::xml_node_struct::append_node(parent, this->alloc, node_pi);
          appended->name = v25;
          parent = appended->parent;
        }
      }
      else
      {
        if ( ((*v25 - 88) & 0xDF) == 0 && ((v25[1] - 77) & 0xDF) == 0 && ((v25[2] - 76) & 0xDF) == 0 && !v25[3] )
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
                  goto LABEL_261;
                }
                return 0;
              }
            }
            else if ( v28 == 10 )
            {
              ++line_count;
            }
            v28 = *++v27;
            if ( !*v27 )
              return 0;
          }
        }
        v30 = pugi::xml_node_struct::append_node(parent, this->alloc, node_pi);
        v30->name = v25;
        if ( (chartype_table[v26] & 8) != 0 )
        {
          for ( i = (unsigned __int8)*v27; (chartype_table[i] & 8) != 0; i = (unsigned __int8)*v27 )
          {
            if ( (_BYTE)i == 10 )
              ++line_count;
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
          if ( *(_WORD *)v27 == 15935 )
            break;
          if ( *v27 == 10 )
            ++line_count;
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
        parent = v30->parent;
      }
      goto LABEL_261;
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
          if ( (optmsk & 4) != 0 )
          {
            v36 = pugi::xml_node_struct::append_node(parent, this->alloc, node_cdata);
            v36->value = v35;
            if ( (optmsk & 0x20) != 0 )
            {
              v37 = `anonymous namespace::strconv_cdata(v35);
              v38 = v37 == 0i64;
            }
            else
            {
              if ( !*v35 )
                return 0;
              do
              {
                if ( *(_WORD *)v35 == 23901 && v35[2] == 62 )
                  break;
                if ( *v35 == 10 )
                  ++line_count;
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
            parent = v36->parent;
            goto LABEL_151;
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
LABEL_151:
                v7 = v37 + 2;
                goto LABEL_261;
              }
            }
            else if ( v39 == 10 )
            {
              ++line_count;
            }
            ++v35;
          }
        }
        if ( v33 != 68 || v13[2] != 79 || v13[3] != 67 || v13[4] != 84 || v13[5] != 89 || v13[6] != 80 || v13[7] != 69 )
          return 0;
        v40 = v13 + 8;
        for ( j = (unsigned __int8)*v40; (chartype_table[j] & 8) != 0; j = (unsigned __int8)*v40 )
        {
          if ( (_BYTE)j == 10 )
            ++line_count;
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
              ++line_count;
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
                ++line_count;
              ++v40;
            }
            if ( *v40 )
            {
              v7 = v40 + 1;
              goto LABEL_261;
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
              ++line_count;
          }
          if ( !*v40 )
            return 0;
          ++v40;
        }
      }
      if ( v13[2] != 45 )
        return 0;
      v34 = v13 + 3;
      if ( (optmsk & 2) != 0 )
      {
        parent = pugi::xml_node_struct::append_node(parent, this->alloc, node_comment);
        parent->value = v34;
      }
      if ( (optmsk & 0x20) != 0 && (optmsk & 2) != 0 )
      {
        v7 = `anonymous namespace::strconv_comment(v34);
        if ( !v7 )
          return 0;
      }
      else
      {
        if ( !*v34 )
          return 0;
        do
        {
          if ( *(_WORD *)v34 == 11565 && v34[2] == 62 )
            break;
          if ( *v34 == 10 )
            ++line_count;
          ++v34;
        }
        while ( *v34 );
        if ( !*v34 )
          return 0;
        if ( (optmsk & 2) != 0 )
          *v34 = 0;
        v7 = v34 + 3;
      }
      if ( (optmsk & 2) != 0 )
        parent = parent->parent;
    }
    else
    {
      if ( chartype_table[v21] >= 0 )
      {
        if ( v21 != 47 )
          return 0;
        v7 = v13 + 1;
        if ( !parent )
          return 0;
        name = parent->name;
        if ( !name )
          return 0;
        for ( k = *v7; *v7; k = *v7 )
        {
          if ( (chartype_table[k] & 0x40) == 0 )
            break;
          v64 = *name++;
          ++v7;
          if ( k != v64 )
            return 0;
        }
        if ( *name )
        {
          if ( error_string )
          {
            filename = "unknown filename, maybe a generated buffer?";
            if ( this->_filename )
              filename = this->_filename;
            v67 = parent->parent;
            if ( v67 )
              v68 = v67->name;
            else
              v68 = "(no parent node)";
            v69 = UFG::qString::FormatEx(
                    &result,
                    "There is a mis-matching xml tag inside \"%s\".  Potentially a upper / lower case error or a missing "
                    "open / close tag.  Search for the tag \"%s\" in \"%s\"\n",
                    v68,
                    parent->name,
                    filename);
            UFG::qString::Set(error_string, v69->mData, v69->mLength, 0i64, 0);
            UFG::qString::~qString(&result);
          }
          return 0;
        }
        parent = parent->parent;
        for ( m = (unsigned __int8)*v7; (chartype_table[m] & 8) != 0; m = (unsigned __int8)*v7 )
        {
          if ( (_BYTE)m == 10 )
            ++line_count;
          ++v7;
        }
        v61 = *v7;
        if ( !*v7 )
          return 0;
LABEL_259:
        if ( v61 != 62 )
          return 0;
        ++v7;
        goto LABEL_261;
      }
      v48 = pugi::xml_allocator::memalloc(this->alloc, 0x58ui64);
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
      v49->parent = parent;
      v50 = parent->last_child;
      if ( v50 )
      {
        v50->next_sibling = v49;
        v49->prev_sibling = parent->last_child;
      }
      else
      {
        parent->first_child = v49;
      }
      parent->last_child = v49;
      parent = v49;
      for ( v49->name = v13; (chartype_table[(unsigned __int8)*v13] & 0x40) != 0; ++v13 )
      {
        if ( *v13 == 10 )
          ++line_count;
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
        parent = v49->parent;
        ++v7;
      }
      else
      {
        if ( v51 == 62 )
          goto LABEL_261;
        if ( (chartype_table[v51] & 8) == 0 )
          return 0;
        while ( 1 )
        {
          if ( (chartype_table[(unsigned __int8)v52] & 8) != 0 )
          {
            do
            {
              if ( (_BYTE)v52 == 10 )
                ++line_count;
              v52 = (unsigned __int8)*++v7;
            }
            while ( (chartype_table[v52] & 8) != 0 );
          }
          if ( !*v7 )
            return 0;
          if ( chartype_table[(unsigned __int8)*v7] >= 0 )
            break;
          v53 = pugi::xml_node_struct::append_attribute(v49, this->alloc);
          for ( v53->name = v7; (chartype_table[(unsigned __int8)*v7] & 0x40) != 0; ++v7 )
          {
            if ( *v7 == 10 )
              ++line_count;
          }
          v54 = *v7;
          if ( !*v7 )
            return 0;
          *v7 = 0;
          v55 = v7 + 1;
          LOBYTE(v56) = *v55;
          if ( !*v55 )
            return 0;
          if ( (chartype_table[v54] & 8) != 0 )
          {
            if ( (chartype_table[(unsigned __int8)v56] & 8) != 0 )
            {
              do
              {
                if ( (_BYTE)v56 == 10 )
                  ++line_count;
                v56 = (unsigned __int8)*++v55;
              }
              while ( (chartype_table[v56] & 8) != 0 );
            }
            v54 = *v55;
            if ( !*v55 )
              return 0;
            ++v55;
          }
          if ( v54 != 61 )
            return 0;
          for ( n = (unsigned __int8)*v55; (chartype_table[n] & 8) != 0; n = (unsigned __int8)*v55 )
          {
            if ( (_BYTE)n == 10 )
              ++line_count;
            ++v55;
          }
          v58 = *v55;
          if ( !*v55 || v58 != 39 && v58 != 34 )
            return 0;
          v59 = v55 + 1;
          v53->value = v59;
          v60 = `anonymous namespace::strconv_attribute(v59, v58, optmsk);
          v7 = v60;
          if ( !v60 )
            return 0;
          v52 = (unsigned __int8)*v60;
          if ( chartype_table[v52] < 0 )
            return 0;
          if ( !(_BYTE)v52 )
            return parent == xmldoc;
        }
        v61 = *v7;
        if ( *v7 != 47 )
          goto LABEL_259;
        if ( v7[1] != 62 )
          return 0;
        parent = v49->parent;
        v7 += 2;
      }
    }
LABEL_261:
    LOBYTE(v10) = *v7;
    if ( !*v7 )
      return parent == xmldoc;
  }
  v20 = *v14;
  if ( *v14 )
  {
    while ( v20 != 60 )
    {
      if ( v20 == 10 )
        ++line_count;
      v20 = *++v15;
      if ( !*v15 )
        return parent == xmldoc;
    }
  }
  if ( *v15 )
  {
    v13 = v15 + 1;
    goto $LOC_TAG;
  }
  return parent == xmldoc;
}

// File Line: 1685
// RVA: 0x8B890
pugi::xml_node_struct *__fastcall pugi::xml_node::get_allocator(pugi::xml_node *this)
{
  pugi::xml_node_struct *root; // rax

  root = this->_root;
  if ( this->_root )
  {
    while ( root && root->parent )
      root = root->parent;
  }
  return root + 1;
}

// File Line: 2448
// RVA: 0x896E0
// attributes: thunk
void __fastcall pugi::xml_document::~xml_document(pugi::xml_document *this)
{
  pugi::xml_document::free(this);
}

// File Line: 2453
// RVA: 0x8B660
void __fastcall pugi::xml_document::create(pugi::xml_document *this)
{
  UFG::qMemoryPool *pool; // rbp
  unsigned __int64 alloc; // rsi
  pugi::xml_memory_block *p_memory; // rbx
  unsigned __int64 size; // rax
  unsigned __int64 v6; // rcx
  char *v7; // rax
  char *v8; // rax

  pool = this->_pool;
  alloc = this->_alloc;
  p_memory = &this->_memory;
  size = this->_memory.size;
  v6 = size + 112;
  if ( size + 112 > 0x8000 )
  {
    v8 = UFG::qMemoryPool::Allocate(pool, 0x8010ui64, "pugi.xml_memory_block", alloc, 1u);
    if ( v8 )
    {
      *(_QWORD *)v8 = 0i64;
      *((_QWORD *)v8 + 1) = 0i64;
    }
    else
    {
      v8 = 0i64;
    }
    p_memory->next = (pugi::xml_memory_block *)v8;
    p_memory = (pugi::xml_memory_block *)v8;
    *((_QWORD *)v8 + 1) = 112i64;
    v7 = v8 + 16;
  }
  else
  {
    v7 = &p_memory->data[size];
    p_memory->size = v6;
  }
  if ( v7 )
  {
    *(_DWORD *)v7 &= 0xFFFFFFF9;
    *(_DWORD *)v7 |= 1u;
    v7[4] |= 3u;
    *((_DWORD *)v7 + 2) &= 0xF8000000;
    *((_QWORD *)v7 + 2) = 0i64;
    *((_QWORD *)v7 + 3) = 0i64;
    *((_QWORD *)v7 + 4) = 0i64;
    *((_QWORD *)v7 + 5) = 0i64;
    *((_QWORD *)v7 + 6) = 0i64;
    *((_QWORD *)v7 + 7) = 0i64;
    *((_QWORD *)v7 + 8) = 0i64;
    *((_QWORD *)v7 + 9) = 0i64;
    *((_QWORD *)v7 + 10) = 0i64;
    *((_QWORD *)v7 + 11) = 0i64;
    *((_QWORD *)v7 + 12) = 0i64;
    *((_QWORD *)v7 + 13) = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  this->_root = (pugi::xml_node_struct *)v7;
  *((_QWORD *)v7 + 11) = p_memory;
  *((_QWORD *)v7 + 12) = alloc;
  *((_QWORD *)v7 + 13) = pool;
}

// File Line: 2462
// RVA: 0x8B780
void __fastcall pugi::xml_document::free(pugi::xml_document *this)
{
  pugi::xml_node_struct *root; // rcx
  pugi::xml_memory_block *next; // rsi
  pugi::xml_memory_block *v4; // rdi
  pugi::xml_allocator *allocator; // rax

  UFG::qMemoryPool::Free(this->_pool, this->_buffer);
  root = this->_root;
  this->_buffer = 0i64;
  if ( root )
    pugi::xml_node_struct::free(root);
  next = this->_memory.next;
  if ( next )
  {
    do
    {
      v4 = next->next;
      allocator = pugi::xml_node::get_allocator(this);
      UFG::qMemoryPool::Free(allocator->_pool, next);
      next = v4;
    }
    while ( v4 );
  }
  this->_memory.next = 0i64;
  this->_memory.size = 0i64;
  pugi::xml_document::create(this);
}

// File Line: 2523
// RVA: 0x8B8B0
__int64 __fastcall pugi::xml_document::load(
        pugi::xml_document *this,
        const char *contents,
        int length,
        unsigned int options)
{
  __int64 v5; // rbx
  char *v8; // rax
  char *v9; // rsi
  pugi::xml_node_struct *root; // r8
  xml_parser v12; // [rsp+30h] [rbp-18h] BYREF

  LODWORD(v5) = length;
  if ( length == -1 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( contents[v5] );
  }
  v8 = UFG::qMemoryPool::Allocate(this->_pool, (int)v5 + 1, "pugi.load", 0i64, 1u);
  v9 = v8;
  if ( !v8 )
    return 3i64;
  UFG::qMemCopy(v8, contents, v5);
  v9[(int)v5] = 0;
  pugi::xml_document::free(this);
  root = this->_root;
  v12.alloc = (pugi::xml_allocator *)&this->_root[1];
  v12._filename = this->_filename;
  if ( `anonymous namespace::xml_parser::parse(&v12, v9, root, options, 0i64, 0i64) )
  {
    this->_buffer = v9;
    return 0i64;
  }
  else
  {
    UFG::qMemoryPool::Free(this->_pool, v9);
    return 4i64;
  }
}

// File Line: 2554
// RVA: 0x8B9B0
signed __int64 __fastcall pugi::xml_document::load_file(
        pugi::xml_document *this,
        const char *name,
        unsigned int options,
        UFG::qString *errorString,
        unsigned int *lineNumber)
{
  char *v9; // rdi
  UFG::qFile *v10; // rax
  UFG::qFile *v11; // rbp
  __int64 FileSize; // r14
  char *v14; // rax
  __int64 v15; // rbx
  pugi::xml_node_struct *root; // r8
  xml_parser v17; // [rsp+30h] [rbp-28h] BYREF

  v9 = SimpleXML::XMLCache::ExtractFromCache(name);
  if ( !v9 )
  {
    v10 = UFG::qOpen(name, QACCESS_READ, 1);
    this->_filename = name;
    v11 = v10;
    if ( !v10 )
      return 1i64;
    FileSize = UFG::qGetFileSize(v10);
    v14 = UFG::qMemoryPool::Allocate(this->_pool, FileSize + 1, "pugi.load", 0i64, 1u);
    v9 = v14;
    if ( !v14 )
    {
      UFG::qClose(v11);
      return 3i64;
    }
    v15 = UFG::qRead(v11, v14, FileSize, 0i64, QSEEK_CUR);
    UFG::qClose(v11);
    if ( v15 != FileSize )
    {
      UFG::qMemoryPool::Free(this->_pool, v9);
      return 2i64;
    }
    v9[FileSize] = 0;
  }
  pugi::xml_document::free(this);
  root = this->_root;
  v17.alloc = (pugi::xml_allocator *)&this->_root[1];
  v17._filename = this->_filename;
  if ( `anonymous namespace::xml_parser::parse(&v17, v9, root, options, errorString, lineNumber) )
  {
    this->_buffer = v9;
    return 0i64;
  }
  else
  {
    UFG::qMemoryPool::Free(this->_pool, v9);
    return 4i64;
  }
}

