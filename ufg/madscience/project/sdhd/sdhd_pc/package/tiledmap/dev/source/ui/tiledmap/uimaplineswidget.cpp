// File Line: 25
// RVA: 0xBCE60
void __fastcall UFG::UIMapLinesWidget::UIMapLinesWidget(UFG::UIMapLinesWidget *this)
{
  *(_WORD *)&this->mClipToPlayerPos = 256;
  this->mVisible = 0;
  *(_QWORD *)&this->mPlayerPos.x = 0i64;
  *(_QWORD *)&this->mPlayerPos.z = 0i64;
  this->mLineData.p = 0i64;
  this->mLineData.capacity = 0;
  this->mActiveLines.p = 0i64;
  *(_QWORD *)&this->mActiveLines.size = 0i64;
}

// File Line: 30
// RVA: 0xCC610
void __fastcall UFG::UIMapLinesWidget::Update(UFG::UIMapLinesWidget *this, float elapsed, UFG::UITiledMapMath *geo)
{
  UFG::UIMapLinesWidget *v3; // rbx
  float v4; // xmm2_4
  float v5; // xmm3_4
  __m128 v6; // xmm0
  float v7; // xmm0_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h]
  UFG::qVector3 dir; // [rsp+30h] [rbp-18h]

  v3 = this;
  if ( this->mClipToPlayerPos )
  {
    if ( UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
    {
      v4 = pos.x;
      v5 = pos.y;
      v6 = (__m128)LODWORD(pos.y);
      v6.m128_f32[0] = (float)((float)(pos.y - v3->mPlayerPos.y) * (float)(pos.y - v3->mPlayerPos.y))
                     + (float)((float)(pos.x - v3->mPlayerPos.x) * (float)(pos.x - v3->mPlayerPos.x));
      if ( COERCE_FLOAT(_mm_sqrt_ps(v6)) > 5.0 )
      {
        v7 = pos.z;
        v3->mChanged = 1;
        v3->mPlayerPos.x = v4;
        v3->mPlayerPos.z = v7;
        v3->mPlayerPos.y = v5;
      }
    }
  }
  if ( v3->mChanged )
  {
    UFG::UIMapLinesWidget::Refresh(v3);
    v3->mChanged = 0;
  }
}

// File Line: 51
// RVA: 0xC4D60
void __fastcall UFG::UIMapLinesWidget::HandleScreenInit(UFG::UIMapLinesWidget *this)
{
  this->mChanged = 1;
}

// File Line: 57
// RVA: 0xCB8C0
void __fastcall UFG::UIMapLinesWidget::SetVisible(UFG::UIMapLinesWidget *this, bool visible)
{
  bool v2; // zf

  v2 = this->mVisible == visible;
  this->mVisible = visible;
  this->mChanged |= !v2;
}

// File Line: 64
// RVA: 0xBE1B0
void __fastcall UFG::UIMapLinesWidget::Add(UFG::UIMapLinesWidget *this, UFG::UIHKMapLine *line)
{
  UFG::UIMapLinesWidget *v2; // rbx

  v2 = this;
  UFG::qArray<UFG::UIHKMapLine,0>::Add(&this->mLineData, line, "qArray.Add");
  v2->mChanged = 1;
}

// File Line: 71
// RVA: 0xBE950
void __fastcall UFG::UIMapLinesWidget::Clear(UFG::UIMapLinesWidget *this)
{
  UFG::UIMapLinesWidget *v1; // rbx
  UFG::UIHKMapLine *v2; // rcx

  v1 = this;
  v2 = this->mLineData.p;
  if ( v2 )
    operator delete[](v2);
  v1->mLineData.p = 0i64;
  *(_QWORD *)&v1->mLineData.size = 0i64;
  v1->mChanged = 1;
}

// File Line: 78
// RVA: 0xC6DC0
void __fastcall UFG::UIMapLinesWidget::Refresh(UFG::UIMapLinesWidget *this)
{
  unsigned int v1; // ebp
  UFG::UIMapLinesWidget *v2; // r14
  float v3; // xmm7_4
  float v4; // xmm8_4
  unsigned int v5; // eax
  float *v6; // rax
  UFG::qVector2 *v7; // rbx
  float v8; // xmm5_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  UFG::qVector2 *v11; // rdx
  float v12; // xmm6_4
  float v13; // xmm7_4
  __int64 v14; // rdi
  unsigned int v15; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  signed __int64 v18; // rax
  __int64 v19; // r15
  unsigned int v20; // edx
  unsigned int v21; // ebx
  UFG::UIHKMapLine *v22; // rdi
  unsigned int v23; // edx
  float v24; // eax
  UFG::UIHKMapLine *v25; // rcx
  float v26; // xmm0_4
  UFG::qVector2 P; // [rsp+90h] [rbp+8h]
  UFG::qVector2 closest_point; // [rsp+98h] [rbp+10h]

  v1 = 0;
  v2 = this;
  this->mActiveLines.size = 0;
  if ( !this->mLineData.size )
    return;
  if ( this->mClipToPlayerPos )
  {
    v3 = this->mPlayerPos.y;
    P.y = this->mPlayerPos.y;
    v4 = this->mPlayerPos.x;
    P.x = this->mPlayerPos.x;
    v5 = UFG::UIMapLinesWidget::GetClosestLineIndex(this, &P);
    v1 = v5;
    if ( v5 )
    {
      v6 = (float *)&v2->mLineData.p[v5 - 1].start;
      v7 = &v2->mLineData.p[v1].start;
      v8 = *v6;
      if ( (float)((float)((float)((float)(v3 - v6[1]) * (float)(v3 - v6[1]))
                         + (float)((float)(v4 - v8) * (float)(v4 - v8)))
                 / (float)((float)((float)(v6[1] - v6[3]) * (float)(v6[1] - v6[3]))
                         + (float)((float)(v8 - v6[2]) * (float)(v8 - v6[2])))) < (float)((float)((float)((float)(v3 - v7[1].y) * (float)(v3 - v7[1].y))
                                                                                                + (float)((float)(v4 - v7[1].x) * (float)(v4 - v7[1].x)))
                                                                                        / (float)((float)((float)(v7->y - v7[1].y) * (float)(v7->y - v7[1].y))
                                                                                                + (float)((float)(v7->x - v7[1].x) * (float)(v7->x - v7[1].x)))) )
      {
        UFG::qGetClosestPointOnSegment(&closest_point, &v2->mLineData.p[v1 - 1].start, &v2->mLineData.p[v1].start, &P);
        v9 = v7->x;
        v10 = v7->y;
LABEL_9:
        v12 = closest_point.x;
        v13 = closest_point.y;
        if ( v9 != closest_point.x || v10 != closest_point.y )
        {
          v14 = v2->mActiveLines.size;
          v15 = v2->mActiveLines.capacity;
          v16 = v14 + 1;
          if ( (signed int)v14 + 1 > v15 )
          {
            if ( v15 )
              v17 = 2 * v15;
            else
              v17 = 1;
            for ( ; v17 < v16; v17 *= 2 )
              ;
            if ( v17 - v16 > 0x10000 )
              v17 = v14 + 65537;
            UFG::qArray<UFG::UIHKMapLine,0>::Reallocate(&v2->mActiveLines, v17, "qArray.Add");
          }
          v2->mActiveLines.size = v16;
          v18 = (signed __int64)&v2->mActiveLines.p[v14];
          *(float *)v18 = v12;
          *(float *)(v18 + 4) = v13;
          *(float *)(v18 + 8) = v9;
          *(float *)(v18 + 12) = v10;
        }
        goto LABEL_21;
      }
      UFG::qGetClosestPointOnSegment(&closest_point, &v2->mLineData.p[v1].start, v7 + 1, &P);
      v9 = v7[1].x;
      v10 = v7[1].y;
    }
    else
    {
      v11 = &v2->mLineData.p->start;
      v9 = v11->x;
      v10 = v11->y;
      UFG::qGetClosestPointOnSegment(&closest_point, v11, v11 + 1, &P);
    }
    ++v1;
    goto LABEL_9;
  }
LABEL_21:
  while ( v1 < v2->mLineData.size )
  {
    v19 = v2->mActiveLines.size;
    v20 = v2->mActiveLines.capacity;
    v21 = v19 + 1;
    v22 = &v2->mLineData.p[v1];
    if ( (signed int)v19 + 1 > v20 )
    {
      if ( v20 )
        v23 = 2 * v20;
      else
        v23 = 1;
      for ( ; v23 < v21; v23 *= 2 )
        ;
      if ( v23 - v21 > 0x10000 )
        v23 = v19 + 65537;
      UFG::qArray<UFG::UIHKMapLine,0>::Reallocate(&v2->mActiveLines, v23, "qArray.Add");
    }
    v2->mActiveLines.size = v21;
    v24 = v22->start.x;
    ++v1;
    v25 = &v2->mActiveLines.p[v19];
    v25->start.y = v22->start.y;
    v25->start.x = v24;
    v26 = v22->end.y;
    v25->end.x = v22->end.x;
    v25->end.y = v26;
  }
}

// File Line: 146
// RVA: 0xC0D90
__int64 __fastcall UFG::UIMapLinesWidget::GetClosestLineIndex(UFG::UIMapLinesWidget *this, UFG::qVector2 *pos)
{
  unsigned int v2; // er11
  float v3; // xmm2_4
  unsigned int v4; // er9
  UFG::qVector2 *v5; // rdi
  UFG::UIMapLinesWidget *v6; // rsi
  unsigned int v7; // er8
  signed __int64 v8; // rax
  UFG::UIHKMapLine *v9; // rax
  float v10; // xmm3_4
  float v11; // xmm4_4
  signed int v12; // ecx
  float *v13; // rdx
  float *v14; // r10
  float v15; // xmm4_4
  float *v16; // rax

  v2 = this->mLineData.size;
  v3 = FLOAT_9999999_0;
  v4 = 0;
  v5 = pos;
  v6 = this;
  v7 = 0;
  v8 = 0i64;
  if ( (signed int)v2 >= 4 )
  {
    v9 = this->mLineData.p;
    v10 = pos->x;
    v11 = pos->y;
    v12 = 2;
    v13 = (float *)&v9[1].start;
    v14 = &v9[2].start.y;
    v8 = 4i64 * (((v2 - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)(v11 - *(v13 - 3)) * (float)(v11 - *(v13 - 3)))
                 + (float)((float)(v10 - *(v13 - 4)) * (float)(v10 - *(v13 - 4)))) < v3 )
      {
        v3 = (float)((float)(v11 - *(v13 - 3)) * (float)(v11 - *(v13 - 3)))
           + (float)((float)(v10 - *(v13 - 4)) * (float)(v10 - *(v13 - 4)));
        v4 = v7;
      }
      if ( (float)((float)((float)(v11 - *(v14 - 4)) * (float)(v11 - *(v14 - 4)))
                 + (float)((float)(v10 - *v13) * (float)(v10 - *v13))) < v3 )
      {
        v3 = (float)((float)(v11 - *(v14 - 4)) * (float)(v11 - *(v14 - 4)))
           + (float)((float)(v10 - *v13) * (float)(v10 - *v13));
        v4 = v12 - 1;
      }
      if ( (float)((float)((float)(v11 - *v14) * (float)(v11 - *v14))
                 + (float)((float)(v10 - v13[4]) * (float)(v10 - v13[4]))) < v3 )
      {
        v3 = (float)((float)(v11 - *v14) * (float)(v11 - *v14)) + (float)((float)(v10 - v13[4]) * (float)(v10 - v13[4]));
        v4 = v12;
      }
      if ( (float)((float)((float)(v11 - v14[4]) * (float)(v11 - v14[4]))
                 + (float)((float)(v10 - v13[8]) * (float)(v10 - v13[8]))) < v3 )
      {
        v3 = (float)((float)(v11 - v14[4]) * (float)(v11 - v14[4]))
           + (float)((float)(v10 - v13[8]) * (float)(v10 - v13[8]));
        v4 = v12 + 1;
      }
      v7 += 4;
      v13 += 16;
      v14 += 16;
      v12 += 4;
    }
    while ( v7 < v2 - 3 );
  }
  if ( v7 < v2 )
  {
    v16 = (float *)&v6->mLineData.p[v8].start;
    do
    {
      v15 = v5->y;
      if ( (float)((float)((float)(v15 - v16[1]) * (float)(v15 - v16[1]))
                 + (float)((float)(v5->x - *v16) * (float)(v5->x - *v16))) < v3 )
      {
        v3 = (float)((float)(v15 - v16[1]) * (float)(v15 - v16[1]))
           + (float)((float)(v5->x - *v16) * (float)(v5->x - *v16));
        v4 = v7;
      }
      ++v7;
      v16 += 4;
    }
    while ( v7 < v2 );
  }
  return v4;
}

