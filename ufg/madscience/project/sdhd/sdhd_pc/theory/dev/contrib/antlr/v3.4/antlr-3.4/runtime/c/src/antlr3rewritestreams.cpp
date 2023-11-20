// File Line: 69
// RVA: 0x25F270
void __fastcall freeRS(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_VECTOR_struct *v1; // rdx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v2; // rbx
  __int64 v3; // rcx
  ANTLR3_VECTOR_struct *v4; // rcx

  v1 = stream->elements;
  v2 = stream;
  if ( v1 )
  {
    if ( v1->factoryMade == 1 )
    {
      v3 = *(_QWORD *)(*((_QWORD *)stream->adaptor->super + 44) + 328i64);
      (*(void (__fastcall **)(__int64))(v3 + 392))(v3);
      v2->elements = 0i64;
    }
    else
    {
      v1->clear(stream->elements);
      v2->freeElements = 1;
    }
  }
  else
  {
    stream->freeElements = 0;
  }
  v4 = v2->rec->state->rStreams;
  v4->add(v4, v2, (void (__fastcall *)(void *))expungeRS);
}

// File Line: 112
// RVA: 0x25F180
void __fastcall freeNodeRS(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_VECTOR_struct *v1; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v2; // rbx
  unsigned int v3; // edi
  ANTLR3_VECTOR_ELEMENT_struct *v4; // rcx
  void (__fastcall **v5)(void *); // rax
  ANTLR3_VECTOR_struct *v6; // rdx
  __int64 v7; // rcx
  void (__fastcall **v8)(void *); // rax
  ANTLR3_VECTOR_struct *v9; // rcx

  v1 = stream->elements;
  v2 = stream;
  if ( v1 )
  {
    v3 = 1;
    if ( v1->count >= 1 )
    {
      do
      {
        v4 = v2->elements->elements;
        v5 = (void (__fastcall **)(void *))v4[v3 - 1].element;
        if ( v5 )
          v5[24](v4[v3 - 1].element);
        ++v3;
      }
      while ( v3 <= v2->elements->count );
    }
    v6 = v2->elements;
    if ( v6->factoryMade == 1 )
    {
      v7 = *(_QWORD *)(*((_QWORD *)v2->adaptor->super + 44) + 328i64);
      (*(void (__fastcall **)(__int64))(v7 + 392))(v7);
      v2->elements = 0i64;
    }
    else
    {
      v6->clear(v2->elements);
      v2->freeElements = 1;
    }
  }
  else
  {
    v8 = (void (__fastcall **)(void *))stream->singleElement;
    if ( v8 )
      v8[24](stream->singleElement);
    v2->singleElement = 0i64;
    v2->freeElements = 0;
  }
  v9 = v2->rec->state->rStreams;
  v9->add(v9, v2, (void (__fastcall *)(void *))expungeRS);
}

// File Line: 178
// RVA: 0x25F150
void __fastcall expungeRS(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v1; // rbx
  ANTLR3_VECTOR_struct *v2; // rax

  v1 = stream;
  if ( stream->freeElements == 1 )
  {
    v2 = stream->elements;
    if ( v2 )
      v2->free(stream->elements);
  }
  antlrFree(v1);
}

// File Line: 191
// RVA: 0x25F020
UFG::allocator::free_link *__fastcall antlr3RewriteRuleElementStreamNewAE(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description)
{
  ANTLR3_RECOGNIZER_SHARED_STATE_struct *v3; // rax
  ANTLR3_BASE_RECOGNIZER_struct *v4; // rbx
  char *v5; // rdi
  ANTLR3_VECTOR_struct *v6; // r9
  ANTLR3_BASE_TREE_ADAPTOR_struct *v7; // rsi
  unsigned int v8; // edx
  UFG::allocator::free_link *result; // rax

  v3 = rec->state;
  v4 = rec;
  v5 = description;
  v6 = v3->rStreams;
  v7 = adaptor;
  v8 = v6->count;
  if ( v8 )
  {
    result = (UFG::allocator::free_link *)v6->remove(v3->rStreams, v8 - 1);
  }
  else
  {
    result = antlrMalloc(0xA8ui64);
    if ( !result )
      return result;
    result[2].mNext = 0i64;
    LOBYTE(result[3].mNext) = 0;
  }
  result[7].mNext = (UFG::allocator::free_link *)v4;
  result[8].mNext = (UFG::allocator::free_link *)reset_2;
  result[5].mNext = (UFG::allocator::free_link *)v7;
  result[9].mNext = (UFG::allocator::free_link *)add;
  result[10].mNext = (UFG::allocator::free_link *)next;
  result[1].mNext = 0i64;
  result[11].mNext = (UFG::allocator::free_link *)nextTree;
  LODWORD(result->mNext) = 0;
  result[17].mNext = (UFG::allocator::free_link *)nextNode;
  LOBYTE(result[6].mNext) = 0;
  result[12].mNext = (UFG::allocator::free_link *)nextToken_0;
  result[4].mNext = (UFG::allocator::free_link *)v5;
  result[13].mNext = (UFG::allocator::free_link *)next;
  result[16].mNext = (UFG::allocator::free_link *)hasNext;
  result[18].mNext = (UFG::allocator::free_link *)size_0;
  result[19].mNext = (UFG::allocator::free_link *)getDescription;
  result[15].mNext = (UFG::allocator::free_link *)UFG::qPropertyList::operator new;
  result[20].mNext = (UFG::allocator::free_link *)freeRS;
  return result;
}

// File Line: 313
// RVA: 0x25F750
UFG::allocator::free_link *__fastcall antlr3RewriteRuleTOKENStreamNewAE(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description)
{
  UFG::allocator::free_link *result; // rax

  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  if ( result )
  {
    result[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
    result[17].mNext = (UFG::allocator::free_link *)nextNodeToken;
  }
  return result;
}

// File Line: 337
// RVA: 0x25F790
UFG::allocator::free_link *__fastcall antlr3RewriteRuleTOKENStreamNewAEE(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description, void *oneElement)
{
  void *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx

  v4 = oneElement;
  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 && v4 )
    ((void (__fastcall *)(UFG::allocator::free_link *, void *, _QWORD))v5[9].mNext)(v5, v4, 0i64);
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[17].mNext = (UFG::allocator::free_link *)nextNodeToken;
  return v6;
}

// File Line: 356
// RVA: 0x25F7F0
UFG::allocator::free_link *__fastcall antlr3RewriteRuleTOKENStreamNewAEV(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description, ANTLR3_VECTOR_struct *vector)
{
  ANTLR3_VECTOR_struct *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::allocator::free_link *v7; // rax

  v4 = vector;
  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 )
  {
    v7 = v5[2].mNext;
    if ( v7 && !LOBYTE(v7[34].mNext) && LOBYTE(v6[3].mNext) == 1 )
      ((void (__fastcall *)(UFG::allocator::free_link *))v7[35].mNext)(v7);
    v6[2].mNext = (UFG::allocator::free_link *)v4;
    LOBYTE(v6[3].mNext) = 0;
  }
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[17].mNext = (UFG::allocator::free_link *)nextNodeToken;
  return v6;
}

// File Line: 377
// RVA: 0x25F610
UFG::allocator::free_link *__fastcall antlr3RewriteRuleSubtreeStreamNewAE(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description)
{
  UFG::allocator::free_link *result; // rax

  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  if ( result )
  {
    result[14].mNext = (UFG::allocator::free_link *)toTreeNode;
    result[17].mNext = (UFG::allocator::free_link *)nextNode;
    result[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  }
  return result;
}

// File Line: 399
// RVA: 0x25F650
ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *__fastcall antlr3RewriteRuleSubtreeStreamNewAEE(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description, void *oneElement)
{
  void *v4; // rdi
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *result; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // rbx

  v4 = oneElement;
  result = (ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *)antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = result;
  if ( result )
  {
    if ( v4 )
      result->add(result, v4, 0i64);
    v6->dup = (void *(__fastcall *)(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *, void *))toTreeNode;
    v6->nextNode = nextNode;
    v6->free = freeNodeRS;
    result = v6;
  }
  return result;
}

// File Line: 422
// RVA: 0x25F6C0
UFG::allocator::free_link *__fastcall antlr3RewriteRuleSubtreeStreamNewAEV(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description, ANTLR3_VECTOR_struct *vector)
{
  ANTLR3_VECTOR_struct *v4; // rdi
  UFG::allocator::free_link *result; // rax
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // rbx
  ANTLR3_VECTOR_struct *v7; // rax

  v4 = vector;
  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = (ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *)result;
  if ( result )
  {
    v7 = (ANTLR3_VECTOR_struct *)result[2].mNext;
    if ( v7 && !v7->factoryMade && v6->freeElements == 1 )
      v7->free(v7);
    v6->elements = v4;
    v6->freeElements = 0;
    v6->dup = (void *(__fastcall *)(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *, void *))toTreeNode;
    v6->nextNode = nextNode;
    v6->free = freeNodeRS;
    result = (UFG::allocator::free_link *)v6;
  }
  return result;
}

// File Line: 446
// RVA: 0x25F4C0
UFG::allocator::free_link *__fastcall antlr3RewriteRuleNODEStreamNewAE(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description)
{
  UFG::allocator::free_link *result; // rax

  result = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  if ( result )
  {
    result[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
    result[15].mNext = (UFG::allocator::free_link *)toTreeNode;
    result[17].mNext = (UFG::allocator::free_link *)nextToken_0;
    result[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  }
  return result;
}

// File Line: 470
// RVA: 0x25F510
UFG::allocator::free_link *__fastcall antlr3RewriteRuleNODEStreamNewAEE(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description, void *oneElement)
{
  void *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx

  v4 = oneElement;
  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 && v4 )
    ((void (__fastcall *)(UFG::allocator::free_link *, void *, _QWORD))v5[9].mNext)(v5, v4, 0i64);
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[15].mNext = (UFG::allocator::free_link *)toTreeNode;
  v6[17].mNext = (UFG::allocator::free_link *)nextToken_0;
  v6[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  return v6;
}

// File Line: 489
// RVA: 0x25F580
UFG::allocator::free_link *__fastcall antlr3RewriteRuleNODEStreamNewAEV(ANTLR3_BASE_TREE_ADAPTOR_struct *adaptor, ANTLR3_BASE_RECOGNIZER_struct *rec, char *description, ANTLR3_VECTOR_struct *vector)
{
  ANTLR3_VECTOR_struct *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::allocator::free_link *v7; // rax

  v4 = vector;
  v5 = antlr3RewriteRuleElementStreamNewAE(adaptor, rec, description);
  v6 = v5;
  if ( v5 )
  {
    v7 = v5[2].mNext;
    if ( v7 && !LOBYTE(v7[34].mNext) && LOBYTE(v6[3].mNext) == 1 )
      ((void (__fastcall *)(UFG::allocator::free_link *))v7[35].mNext)(v7);
    v6[2].mNext = (UFG::allocator::free_link *)v4;
    LOBYTE(v6[3].mNext) = 0;
  }
  v6[14].mNext = (UFG::allocator::free_link *)TargetVisibleInAIDataCondition::CreateClone;
  v6[15].mNext = (UFG::allocator::free_link *)toTreeNode;
  v6[17].mNext = (UFG::allocator::free_link *)nextToken_0;
  v6[20].mNext = (UFG::allocator::free_link *)freeNodeRS;
  return v6;
}

// File Line: 514
// RVA: 0x25F480
void __fastcall reset_2(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  stream->dirty = 1;
  stream->cursor = 0;
}

// File Line: 523
// RVA: 0x25EF50
void __fastcall add(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream, void *el, void (__fastcall *freePtr)(void *))
{
  ANTLR3_VECTOR_struct *v3; // rax
  void (__fastcall *v4)(void *); // rsi
  void *v5; // rdi
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v6; // rbx
  __int64 v7; // rcx
  __int64 v8; // rax

  if ( el )
  {
    v3 = stream->elements;
    v4 = freePtr;
    v5 = el;
    v6 = stream;
    if ( v3 && v3->count )
    {
      ((void (__fastcall *)(ANTLR3_VECTOR_struct *))v3->add)(stream->elements);
    }
    else if ( stream->singleElement )
    {
      if ( !v3 )
      {
        v7 = *(_QWORD *)(*((_QWORD *)stream->adaptor->super + 44) + 328i64);
        v8 = (*(__int64 (__fastcall **)(__int64))(v7 + 384))(v7);
        v6->freeElements = 1;
        v6->elements = (ANTLR3_VECTOR_struct *)v8;
      }
      v6->elements->add(v6->elements, v6->singleElement, v4);
      v6->elements->add(v6->elements, v5, v4);
      v6->singleElement = 0i64;
    }
    else
    {
      stream->singleElement = el;
    }
  }
}

// File Line: 572
// RVA: 0x25F430
ANTLR3_BASE_TREE_struct *__fastcall nextTree(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v1; // rbx
  unsigned int v2; // eax
  __int64 v4; // rax

  v1 = stream;
  v2 = ((__int64 (*)(void))stream->size)();
  if ( !v1->dirty && (v1->cursor < v2 || v2 != 1) )
    return (ANTLR3_BASE_TREE_struct *)v1->_next(v1);
  v4 = (__int64)v1->_next(v1);
  return (ANTLR3_BASE_TREE_struct *)v1->dup(v1, (void *)v4);
}

// File Line: 605
// RVA: 0x25F350
__int64 __fastcall next(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v1; // rbx
  unsigned int v2; // eax
  __int64 v3; // rax

  v1 = stream;
  v2 = ((__int64 (*)(void))stream->size)();
  if ( v1->cursor < v2 || v2 != 1 )
    return v1->_next(v1);
  v3 = (__int64)v1->_next(v1);
  return v1->dup(v1, (void *)v3);
}

// File Line: 629
// RVA: 0x25EED0
ANTLR3_BASE_TREE_struct *__fastcall next(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v1; // rbx
  unsigned int v2; // eax
  ANTLR3_BASE_TREE_struct *result; // rax
  void *v4; // rdx
  __int64 v5; // rax

  v1 = stream;
  v2 = ((__int64 (*)(void))stream->size)();
  if ( !v2 )
    return 0i64;
  if ( v1->cursor < v2 )
  {
    if ( v1->singleElement )
    {
      v4 = v1->singleElement;
      ++v1->cursor;
      result = v1->toTree(v1, v4);
    }
    else
    {
      v5 = ((__int64 (__fastcall *)(ANTLR3_VECTOR_struct *))v1->elements->get)(v1->elements);
      result = v1->toTree(v1, (void *)v5);
      ++v1->cursor;
    }
  }
  else
  {
    if ( v2 != 1 )
      return 0i64;
    result = v1->toTree(v1, v1->singleElement);
  }
  return result;
}

// File Line: 694
// RVA: 0x25F4B0
ANTLR3_BASE_TREE_struct *__fastcall toTreeNode(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream, void *element)
{
  return (ANTLR3_BASE_TREE_struct *)stream->adaptor->dupNode(stream->adaptor, element);
}

// File Line: 735
// RVA: 0x25F310
bool __fastcall hasNext(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_VECTOR_struct *v1; // rax
  bool result; // al

  result = 1;
  if ( !stream->singleElement || stream->cursor >= 1 )
  {
    v1 = stream->elements;
    if ( !v1 || stream->cursor >= v1->size(stream->elements) )
      result = 0;
  }
  return result;
}

// File Line: 752
// RVA: 0x25F3F0
ANTLR3_BASE_TREE_struct *__fastcall nextNodeToken(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_BASE_TREE_ADAPTOR_struct *v1; // rbx
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v2; // rdi
  __int64 v3; // rax

  v1 = stream->adaptor;
  v2 = stream;
  v3 = ((__int64 (*)(void))stream->_next)();
  return (ANTLR3_BASE_TREE_struct *)v1->create(v2->adaptor, (ANTLR3_COMMON_TOKEN_struct *)v3);
}

// File Line: 758
// RVA: 0x25F420
__int64 __fastcall nextToken_0(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  return ((__int64 (*)(void))stream->_next)();
}

// File Line: 773
// RVA: 0x25F390
ANTLR3_BASE_TREE_struct *__fastcall nextNode(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *v1; // rbx
  ANTLR3_BASE_TREE_struct *v2; // rdi
  unsigned int v3; // eax
  ANTLR3_BASE_TREE_struct *result; // rax

  v1 = stream;
  v2 = (ANTLR3_BASE_TREE_struct *)((__int64 (*)(void))stream->_next)();
  v3 = v1->size(v1);
  if ( v1->dirty == 1 || v1->cursor > v3 && v3 == 1 )
    result = (ANTLR3_BASE_TREE_struct *)v1->adaptor->dupNode(v1->adaptor, v2);
  else
    result = v2;
  return result;
}

// File Line: 796
// RVA: 0x25F490
signed __int64 __fastcall size_0(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  signed __int64 result; // rax
  ANTLR3_VECTOR_struct *v2; // rcx

  result = 0i64;
  if ( stream->singleElement )
    return 1i64;
  v2 = stream->elements;
  if ( v2 )
    result = v2->count;
  return result;
}

// File Line: 821
// RVA: 0x25F2F0
void *__fastcall getDescription(ANTLR3_REWRITE_RULE_ELEMENT_STREAM_struct *stream)
{
  if ( !stream->elementDescription )
    stream->elementDescription = "<unknown source>";
  return stream->elementDescription;
}

