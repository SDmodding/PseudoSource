// File Line: 53
// RVA: 0x1453290
void dynamic_initializer_for__UFG::DrawInfo::msDefault__()
{
  LODWORD(UFG::DrawInfo::msDefault.mColour1.r) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour1.g) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour1.b) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour1.a) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.r) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.g) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.b) = (_DWORD)FLOAT_1_0;
  LODWORD(UFG::DrawInfo::msDefault.mColour2.a) = (_DWORD)FLOAT_1_0;
}

// File Line: 180
// RVA: 0x170B0
void __fastcall Render::DebugLineStrip::DebugLineStrip(Render::DebugLineStrip *this, UFG::qLinearAllocator *pool, UFG::qVector3 *p0, UFG::qVector3 *p1, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *), bool is_screen_coords)
{
  UFG::qVector3 *v8; // rdi
  UFG::qVector3 *v9; // rsi
  Render::DebugLineStrip *v10; // rbx
  char *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm2_4

  v8 = p1;
  v9 = p0;
  v10 = this;
  this->mPrev = (UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *)&this->mPrev;
  this->m_LocalWorld = local_world;
  this->m_NumPoints = 2;
  this->m_DrawInfo.mColour1.r = UFG::DrawInfo::msDefault.mColour1.r;
  this->m_DrawInfo.mColour1.g = UFG::DrawInfo::msDefault.mColour1.g;
  this->m_DrawInfo.mColour1.b = UFG::DrawInfo::msDefault.mColour1.b;
  this->m_DrawInfo.mColour1.a = UFG::DrawInfo::msDefault.mColour1.a;
  this->m_DrawInfo.mColour2.r = UFG::DrawInfo::msDefault.mColour2.r;
  this->m_DrawInfo.mColour2.g = UFG::DrawInfo::msDefault.mColour2.g;
  this->m_DrawInfo.mColour2.b = UFG::DrawInfo::msDefault.mColour2.b;
  this->m_DrawInfo.mColour2.a = UFG::DrawInfo::msDefault.mColour2.a;
  this->m_DrawInfo.mScale = UFG::DrawInfo::msDefault.mScale;
  this->m_DrawInfo.mAlphaBlend = UFG::DrawInfo::msDefault.mAlphaBlend;
  this->m_DrawInfo.mDepthBuffer = UFG::DrawInfo::msDefault.mDepthBuffer;
  this->m_DrawInfo.mFaceCull = UFG::DrawInfo::msDefault.mFaceCull;
  this->m_DrawInfo.mDepthBias = UFG::DrawInfo::msDefault.mDepthBias;
  this->m_DrawInfo.mPreDrawCallback = UFG::DrawInfo::msDefault.mPreDrawCallback;
  this->m_DrawInfo.mColour1.r = colour->r;
  this->m_DrawInfo.mColour1.g = colour->g;
  this->m_DrawInfo.mColour1.b = colour->b;
  this->m_DrawInfo.mColour1.a = colour->a;
  this->m_DrawInfo.mColour2.r = colour->r;
  this->m_DrawInfo.mColour2.g = colour->g;
  this->m_DrawInfo.mColour2.b = colour->b;
  this->m_DrawInfo.mColour2.a = colour->a;
  this->m_DrawInfo.mPreDrawCallback = pre_draw_callback;
  v11 = UFG::qLinearAllocator::Malloc(pool, 12 * this->m_NumPoints, 4u);
  v10->m_Points = (UFG::qVector3 *)v11;
  if ( v11 )
  {
    v12 = v9->y;
    v13 = v9->z;
    *(float *)v11 = v9->x;
    *((float *)v11 + 1) = v12;
    *((float *)v11 + 2) = v13;
    v14 = &v10->m_Points->x;
    v15 = v8->y;
    v16 = v8->z;
    v14[3] = v8->x;
    v14[4] = v15;
    v14[5] = v16;
  }
  v10->m_NumPoints |= is_screen_coords != 0 ? 0x10000 : 0;
}

// File Line: 197
// RVA: 0x17260
void __fastcall Render::DebugLineStrip::DebugLineStrip(Render::DebugLineStrip *this, UFG::qLinearAllocator *pool, UFG::qVector3 *points, const int num_points, UFG::DrawInfo *info, UFG::qMatrix44 *local_world)
{
  int v6; // edi
  UFG::qVector3 *v7; // rsi
  Render::DebugLineStrip *v8; // rbx
  char *v9; // rax

  v6 = num_points;
  v7 = points;
  v8 = this;
  this->mPrev = (UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *)&this->mPrev;
  this->m_LocalWorld = local_world;
  this->m_NumPoints = num_points;
  this->m_DrawInfo.mColour1.r = info->mColour1.r;
  this->m_DrawInfo.mColour1.g = info->mColour1.g;
  this->m_DrawInfo.mColour1.b = info->mColour1.b;
  this->m_DrawInfo.mColour1.a = info->mColour1.a;
  this->m_DrawInfo.mColour2.r = info->mColour2.r;
  this->m_DrawInfo.mColour2.g = info->mColour2.g;
  this->m_DrawInfo.mColour2.b = info->mColour2.b;
  this->m_DrawInfo.mColour2.a = info->mColour2.a;
  this->m_DrawInfo.mScale = info->mScale;
  this->m_DrawInfo.mAlphaBlend = info->mAlphaBlend;
  this->m_DrawInfo.mDepthBuffer = info->mDepthBuffer;
  this->m_DrawInfo.mFaceCull = info->mFaceCull;
  this->m_DrawInfo.mDepthBias = info->mDepthBias;
  this->m_DrawInfo.mPreDrawCallback = info->mPreDrawCallback;
  v9 = UFG::qLinearAllocator::Malloc(pool, 12 * this->m_NumPoints, 4u);
  v8->m_Points = (UFG::qVector3 *)v9;
  if ( v9 )
    UFG::qMemCopy(v9, v7, 12 * v6);
}

// File Line: 227
// RVA: 0x17350
void __fastcall Render::DebugTriStrip::DebugTriStrip(Render::DebugTriStrip *this, UFG::qLinearAllocator *pool, UFG::qVector3 *points, int num_points, UFG::DrawInfo *info, UFG::qMatrix44 *local_world, bool is_screen_coords)
{
  int v7; // edi
  UFG::qVector3 *v8; // rsi
  Render::DebugTriStrip *v9; // rbx
  char *v10; // rax

  v7 = num_points;
  v8 = points;
  v9 = this;
  this->mPrev = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&this->mPrev;
  this->mNumPoints = num_points;
  this->mDrawInfo.mColour1.r = info->mColour1.r;
  this->mDrawInfo.mColour1.g = info->mColour1.g;
  this->mDrawInfo.mColour1.b = info->mColour1.b;
  this->mDrawInfo.mColour1.a = info->mColour1.a;
  this->mDrawInfo.mColour2.r = info->mColour2.r;
  this->mDrawInfo.mColour2.g = info->mColour2.g;
  this->mDrawInfo.mColour2.b = info->mColour2.b;
  this->mDrawInfo.mColour2.a = info->mColour2.a;
  this->mDrawInfo.mScale = info->mScale;
  this->mDrawInfo.mAlphaBlend = info->mAlphaBlend;
  this->mDrawInfo.mDepthBuffer = info->mDepthBuffer;
  this->mDrawInfo.mFaceCull = info->mFaceCull;
  this->mDrawInfo.mDepthBias = info->mDepthBias;
  this->mDrawInfo.mPreDrawCallback = info->mPreDrawCallback;
  this->mLocalWorld = local_world;
  this->mPoints = 0i64;
  this->mSortMetric = 0.0;
  this->mInFront = info->mDepthBias;
  v10 = UFG::qLinearAllocator::Malloc(pool, 12 * this->mNumPoints, 4u);
  v9->mPoints = (UFG::qVector3 *)v10;
  if ( v10 )
    UFG::qMemCopy(v10, v8, 12 * v7);
  v9->mNumPoints |= is_screen_coords != 0 ? 0x10000 : 0;
}

// File Line: 248
// RVA: 0x16D40
void __fastcall Render::DebugAABB::DebugAABB(Render::DebugAABB *this, UFG::qVector3 *min, UFG::qVector3 *max, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4

  this->mPrev = (UFG::qNode<Render::DebugAABB,Render::DebugAABB> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::DebugAABB,Render::DebugAABB> *)&this->mPrev;
  v6 = min->y;
  v7 = min->z;
  this->m_Min.x = min->x;
  this->m_Min.y = v6;
  this->m_Min.z = v7;
  v8 = max->y;
  v9 = max->z;
  this->m_Max.x = max->x;
  this->m_Max.y = v8;
  this->m_Max.z = v9;
  this->m_Colour.r = colour->r;
  this->m_Colour.g = colour->g;
  this->m_Colour.b = colour->b;
  this->m_Colour.a = colour->a;
  this->m_LocalWorld = local_world;
  this->m_PreDrawCallback = pre_draw_callback;
}

// File Line: 296
// RVA: 0x16E70
void __fastcall Render::DebugCylinder::DebugCylinder(Render::DebugCylinder *this, UFG::qVector3 *min, UFG::qVector3 *max, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  this->mPrev = (UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *)&this->mPrev;
  v7 = min->y;
  v8 = min->z;
  this->m_Min.x = min->x;
  this->m_Min.y = v7;
  this->m_Min.z = v8;
  v9 = max->y;
  v10 = max->z;
  this->m_Max.x = max->x;
  this->m_Max.y = v9;
  this->m_Max.z = v10;
  this->m_Radius = radius;
  this->m_Colour.r = colour->r;
  this->m_Colour.g = colour->g;
  this->m_Colour.b = colour->b;
  this->m_Colour.a = colour->a;
  this->m_LocalWorld = local_world;
  this->m_PreDrawCallback = pre_draw_callback;
}

// File Line: 321
// RVA: 0x16DD0
void __fastcall Render::DebugCircle::DebugCircle(Render::DebugCircle *this, UFG::qVector3 *centre, UFG::qVector3 *normal, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  this->mPrev = (UFG::qNode<Render::DebugCircle,Render::DebugCircle> *)&this->mPrev;
  this->mNext = (UFG::qNode<Render::DebugCircle,Render::DebugCircle> *)&this->mPrev;
  v7 = centre->y;
  v8 = centre->z;
  this->m_Centre.x = centre->x;
  this->m_Centre.y = v7;
  this->m_Centre.z = v8;
  v9 = normal->y;
  v10 = normal->z;
  this->m_Normal.x = normal->x;
  this->m_Normal.y = v9;
  this->m_Normal.z = v10;
  this->m_Radius = radius;
  this->m_Colour.r = colour->r;
  this->m_Colour.g = colour->g;
  this->m_Colour.b = colour->b;
  this->m_Colour.a = colour->a;
  this->m_LocalWorld = local_world;
  this->m_PreDrawCallback = pre_draw_callback;
}

// File Line: 417
// RVA: 0x16F10
void __fastcall Render::DebugData::DebugData(Render::DebugData *this, int debug_pool_size)
{
  unsigned int v2; // edi
  Render::DebugData *v3; // rsi
  char *v4; // rax
  unsigned int v5; // ebx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qList<Render::DebugText,Render::DebugText,1,0> *v8; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugRect,Render::DebugRect,1,0> *v9; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugIcon,Render::DebugIcon,1,0> *v10; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *v11; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v12; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugAABB,Render::DebugAABB,1,0> *v13; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugSphere,Render::DebugSphere,1,0> *v14; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugCylinder,Render::DebugCylinder,1,0> *v15; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugCircle,Render::DebugCircle,1,0> *v16; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugArc,Render::DebugArc,1,0> *v17; // [rsp+60h] [rbp+18h]
  UFG::qList<Render::DebugAxis,Render::DebugAxis,1,0> *v18; // [rsp+60h] [rbp+18h]

  v2 = debug_pool_size;
  v3 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mDebugFontHandle.mPrev);
  v8 = &v3->mDebugTextLines;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  v9 = &v3->mDebugRects;
  v9->mNode.mPrev = &v9->mNode;
  v9->mNode.mNext = &v9->mNode;
  v10 = &v3->mDebugIcons;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
  v11 = &v3->mDebugLineStrips;
  v11->mNode.mPrev = &v11->mNode;
  v11->mNode.mNext = &v11->mNode;
  v12 = &v3->mDebugTriStrips;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
  v13 = &v3->mDebugAABB;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v14 = &v3->mDebugSphere;
  v14->mNode.mPrev = &v14->mNode;
  v14->mNode.mNext = &v14->mNode;
  v15 = &v3->mDebugCylinder;
  v15->mNode.mPrev = &v15->mNode;
  v15->mNode.mNext = &v15->mNode;
  v16 = &v3->mDebugCircle;
  v16->mNode.mPrev = &v16->mNode;
  v16->mNode.mNext = &v16->mNode;
  v17 = &v3->mDebugArc;
  v17->mNode.mPrev = &v17->mNode;
  v17->mNode.mNext = &v17->mNode;
  v18 = &v3->mDebugAxis;
  v18->mNode.mPrev = &v18->mNode;
  v18->mNode.mNext = &v18->mNode;
  UFG::qLinearAllocator::qLinearAllocator(&v3->mDebugMemory);
  v3->mDebugPoolSize = v2;
  v4 = UFG::qMalloc(v2, "DebugData::mDebugPool", 0i64);
  v3->mDebugPool = v4;
  UFG::qLinearAllocator::Init(&v3->mDebugMemory, v4, v3->mDebugPoolSize, 0i64, 0i64);
  v3->mHaveExceededPool = 0;
  v5 = UFG::qStringHash32("LucidaConsole", 0xFFFFFFFF);
  v6 = `UFG::qGetResourceInventory<Render::Font>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::Font>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x69FCCB4Cu);
    `UFG::qGetResourceInventory<Render::Font>::`2::result = v6;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v3->mDebugFontHandle.mPrev, 0x69FCCB4Cu, v5, v6);
}

// File Line: 432
// RVA: 0x17790
UFG::qMatrix44 *__fastcall Render::DebugData::AllocMatrix(Render::DebugData *this, UFG::qMatrix44 *matrix)
{
  UFG::qMatrix44 *v2; // rbx
  UFG::qMatrix44 *result; // rax
  UFG::qVector4 v4; // xmm3
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm1

  v2 = matrix;
  if ( !matrix )
    return 0i64;
  result = (UFG::qMatrix44 *)UFG::qLinearAllocator::Malloc(&this->mDebugMemory, 0x40u, 0x10u);
  if ( !result )
    return 0i64;
  v4 = v2->v1;
  v5 = v2->v2;
  v6 = v2->v3;
  result->v0 = v2->v0;
  result->v1 = v4;
  result->v2 = v5;
  result->v3 = v6;
  return result;
}

// File Line: 502
// RVA: 0x18EB0
void Render::DebugDrawContext::DrawTextA(Render::DebugDrawContext *this, int x, int y, UFG::qColour *colour, const char *format, ...)
{
  Render::DebugData *fontName; // r10
  va_list va; // [rsp+78h] [rbp+30h]

  va_start(va, format);
  fontName = this->mDebugData;
  if ( fontName )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(
        this,
        x,
        y,
        9u,
        (int)format,
        &fontName->mDebugFontHandle,
        colour,
        format,
        va);
  }
}

// File Line: 532
// RVA: 0x18E60
void Render::DebugDrawContext::DrawText(Render::DebugDrawContext *this, UFG::qVector3 *world_position, UFG::qColour *colour, const char *format, ...)
{
  Render::DebugData *v4; // rax
  va_list va; // [rsp+70h] [rbp+28h]

  va_start(va, format);
  v4 = this->mDebugData;
  if ( v4 )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(
        this,
        world_position,
        9u,
        &v4->mDebugFontHandle,
        (int)v4,
        colour,
        format,
        va);
  }
}

// File Line: 572
// RVA: 0x18F40
void Render::DebugDrawContext::DrawTextAligned(Render::DebugDrawContext *this, int x, int y, unsigned int align_flags, Render::FontHandle *fontName, UFG::qColour *colour, const char *format, ...)
{
  va_list va; // [rsp+88h] [rbp+40h]

  va_start(va, format);
  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(this, x, y, align_flags, (int)fontName, fontName, colour, format, va);
  }
}

// File Line: 594
// RVA: 0x18F00
void Render::DebugDrawContext::DrawTextAligned(Render::DebugDrawContext *this, UFG::qVector3 *world_position, unsigned int align_flags, Render::FontHandle *fontName, UFG::qColour *colour, const char *format, ...)
{
  va_list va; // [rsp+80h] [rbp+38h]

  va_start(va, format);
  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
      Render::DebugDrawContext::DrawTextArgs(
        this,
        world_position,
        align_flags,
        fontName,
        (int)colour,
        colour,
        format,
        va);
  }
}

// File Line: 607
// RVA: 0x19110
void __usercall Render::DebugDrawContext::DrawTextArgs(Render::DebugDrawContext *this@<rcx>, int x@<edx>, int y@<r8d>, unsigned int alignment@<r9d>, int a5@<eax>, Render::FontHandle *fontName, UFG::qColour *colour, const char *format, char *args)
{
  unsigned int v9; // ebp
  int v10; // er14
  int v11; // er15
  Render::DebugDrawContext *v12; // rbx
  int v13; // eax
  int v14; // esi
  char *v15; // rax
  char *v16; // rdi
  char *v17; // rax
  char *v18; // rdx
  UFG::qColour v19; // xmm0
  UFG::qList<Render::DebugText,Render::DebugText,1,0> *v20; // rcx
  UFG::qNode<Render::DebugText,Render::DebugText> *v21; // rax
  char dest; // [rsp+30h] [rbp-2018h]
  char *v23; // [rsp+2050h] [rbp+8h]

  v9 = alignment;
  v10 = y;
  v11 = x;
  v12 = this;
  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      v13 = UFG::qVSPrintf(&dest, a5 - 48, format, args);
      if ( v13 )
      {
        v14 = v13 + 1;
        v15 = UFG::qLinearAllocator::Malloc(&v12->mDebugData->mDebugMemory, v13 + 1, 1u);
        v16 = v15;
        if ( v15
          && (UFG::qStringCopy(v15, v14, &dest, -1),
              v17 = UFG::qLinearAllocator::Malloc(&v12->mDebugData->mDebugMemory, 0x48u, 0x10u),
              v18 = v17,
              (v23 = v17) != 0i64) )
        {
          v19 = *colour;
          *(_QWORD *)v17 = v17;
          *((_QWORD *)v17 + 1) = v17;
          *((_QWORD *)v17 + 3) = fontName;
          *((_DWORD *)v17 + 13) = v9;
          *((_QWORD *)v17 + 2) = v16;
          *((UFG::qColour *)v17 + 2) = v19;
          *((float *)v17 + 14) = (float)v11;
          *((float *)v17 + 15) = (float)v10;
          *((_DWORD *)v17 + 12) = 0;
          v20 = &v12->mDebugData->mDebugTextLines;
          v21 = v20->mNode.mPrev;
          v21->mNext = (UFG::qNode<Render::DebugText,Render::DebugText> *)v18;
          *(_QWORD *)v18 = v21;
          *((_QWORD *)v18 + 1) = v20;
          v20->mNode.mPrev = (UFG::qNode<Render::DebugText,Render::DebugText> *)v18;
        }
        else
        {
          v12->mDebugData->mHaveExceededPool = 1;
        }
      }
    }
  }
}

// File Line: 641
// RVA: 0x18F90
void __usercall Render::DebugDrawContext::DrawTextArgs(Render::DebugDrawContext *this@<rcx>, UFG::qVector3 *world_position@<rdx>, unsigned int alignment@<r8d>, Render::FontHandle *fontName@<r9>, int a5@<eax>, UFG::qColour *colour, const char *format, char *args)
{
  Render::FontHandle *v8; // r14
  unsigned int v9; // er15
  UFG::qVector3 *v10; // rbp
  Render::DebugDrawContext *v11; // rbx
  int v12; // eax
  int v13; // esi
  char *v14; // rax
  char *v15; // rdi
  char *v16; // rax
  char *v17; // rdx
  UFG::qColour v18; // xmm0
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  UFG::qList<Render::DebugText,Render::DebugText,1,0> *v22; // rcx
  UFG::qNode<Render::DebugText,Render::DebugText> *v23; // rax
  char dest; // [rsp+30h] [rbp-2018h]
  char *v25; // [rsp+2050h] [rbp+8h]

  v8 = fontName;
  v9 = alignment;
  v10 = world_position;
  v11 = this;
  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      v12 = UFG::qVSPrintf(&dest, a5 - 48, format, args);
      if ( v12 )
      {
        v13 = v12 + 1;
        v14 = UFG::qLinearAllocator::Malloc(&v11->mDebugData->mDebugMemory, v12 + 1, 1u);
        v15 = v14;
        if ( v14
          && (UFG::qStringCopy(v14, v13, &dest, -1),
              v16 = UFG::qLinearAllocator::Malloc(&v11->mDebugData->mDebugMemory, 0x48u, 0x10u),
              v17 = v16,
              (v25 = v16) != 0i64) )
        {
          v18 = *colour;
          v19 = v10->x;
          v20 = v10->y;
          v21 = v10->z;
          *(_QWORD *)v16 = v16;
          *((_QWORD *)v16 + 1) = v16;
          *((_QWORD *)v16 + 3) = v8;
          *((_QWORD *)v16 + 2) = v15;
          *((UFG::qColour *)v16 + 2) = v18;
          *((float *)v16 + 14) = v19;
          *((float *)v16 + 15) = v20;
          *((float *)v16 + 16) = v21;
          *((_DWORD *)v16 + 12) = 1;
          *((_DWORD *)v16 + 13) = v9;
          v22 = &v11->mDebugData->mDebugTextLines;
          v23 = v22->mNode.mPrev;
          v23->mNext = (UFG::qNode<Render::DebugText,Render::DebugText> *)v17;
          *(_QWORD *)v17 = v23;
          *((_QWORD *)v17 + 1) = v22;
          v22->mNode.mPrev = (UFG::qNode<Render::DebugText,Render::DebugText> *)v17;
        }
        else
        {
          v11->mDebugData->mHaveExceededPool = 1;
        }
      }
    }
  }
}

// File Line: 697
// RVA: 0x18C10
void __fastcall Render::DebugDrawContext::DrawRect(Render::DebugDrawContext *this, float x, float y, float w, float h, UFG::qColour *colour)
{
  Render::DebugDrawContext *v6; // rbx
  Render::DebugData *v7; // rcx
  char *v8; // rax
  char *v9; // rdx
  UFG::qList<Render::DebugRect,Render::DebugRect,1,0> *v10; // rcx
  UFG::qNode<Render::DebugRect,Render::DebugRect> *v11; // rax

  v6 = this;
  v7 = this->mDebugData;
  if ( v7 && !gDisableDebugDraw )
  {
    v8 = UFG::qLinearAllocator::Malloc(&v7->mDebugMemory, 0x30u, 0x10u);
    v9 = v8;
    if ( v8 )
    {
      *(_QWORD *)v8 = v8;
      *((_QWORD *)v8 + 1) = v8;
      *((float *)v8 + 4) = x;
      *((float *)v8 + 5) = y;
      *((float *)v8 + 6) = w;
      *((float *)v8 + 7) = h;
      *((_DWORD *)v8 + 8) = LODWORD(colour->r);
      *((_DWORD *)v8 + 9) = LODWORD(colour->g);
      *((_DWORD *)v8 + 10) = LODWORD(colour->b);
      *((_DWORD *)v8 + 11) = LODWORD(colour->a);
      v10 = &v6->mDebugData->mDebugRects;
      v11 = v10->mNode.mPrev;
      v11->mNext = (UFG::qNode<Render::DebugRect,Render::DebugRect> *)v9;
      *(_QWORD *)v9 = v11;
      *((_QWORD *)v9 + 1) = v10;
      v10->mNode.mPrev = (UFG::qNode<Render::DebugRect,Render::DebugRect> *)v9;
    }
    else
    {
      v6->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 716
// RVA: 0x18640
void __fastcall Render::DebugDrawContext::DrawLine(Render::DebugDrawContext *this, UFG::qVector3 *p0, UFG::qVector3 *p1, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *), bool is_screen_coords)
{
  UFG::qColour *v7; // rsi
  UFG::qVector3 *v8; // rbp
  UFG::qVector3 *v9; // r14
  Render::DebugDrawContext *v10; // rbx
  Render::DebugData *v11; // rcx
  UFG::qMatrix44 *v12; // rdi
  char *v13; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v14; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *v15; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v16; // rcx

  v7 = colour;
  v8 = p1;
  v9 = p0;
  v10 = this;
  v11 = this->mDebugData;
  if ( v11 && !gDisableDebugDraw )
  {
    v12 = 0i64;
    if ( (!local_world || (v12 = Render::DebugData::AllocMatrix(v11, local_world)) != 0i64)
      && (v13 = UFG::qLinearAllocator::Malloc(&v10->mDebugData->mDebugMemory, 0x60u, 0x10u)) != 0i64
      && (Render::DebugLineStrip::DebugLineStrip(
            (Render::DebugLineStrip *)v13,
            &v10->mDebugData->mDebugMemory,
            v9,
            v8,
            v7,
            v12,
            pre_draw_callback,
            is_screen_coords),
          v14)
      && v14[1].mPrev )
    {
      v15 = &v10->mDebugData->mDebugLineStrips;
      v16 = v15->mNode.mPrev;
      v16->mNext = v14;
      v14->mPrev = v16;
      v14->mNext = &v15->mNode;
      v15->mNode.mPrev = v14;
    }
    else
    {
      v10->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 749
// RVA: 0x17E70
void __fastcall Render::DebugDrawContext::DrawArrow(Render::DebugDrawContext *this, UFG::qVector3 *p0, UFG::qVector3 *p1, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm13_4
  float v9; // xmm12_4
  float v10; // xmm14_4
  __m128 v11; // xmm10
  float v12; // xmm7_4
  float v13; // xmm11_4
  __m128 v14; // xmm1
  float v15; // xmm9_4
  float v16; // xmm10_4
  float v17; // xmm6_4
  float v18; // xmm8_4
  int v19; // xmm9_4
  float v20; // xmm1_4
  int v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm6_4
  UFG::qVector3 line_points; // [rsp+30h] [rbp-E8h]
  float v27; // [rsp+3Ch] [rbp-DCh]
  int v28; // [rsp+40h] [rbp-D8h]
  int v29; // [rsp+44h] [rbp-D4h]
  float v30; // [rsp+48h] [rbp-D0h]
  float v31; // [rsp+4Ch] [rbp-CCh]
  float v32; // [rsp+50h] [rbp-C8h]
  float v33; // [rsp+54h] [rbp-C4h]
  float v34; // [rsp+58h] [rbp-C0h]
  float v35; // [rsp+5Ch] [rbp-BCh]
  float v36; // [rsp+60h] [rbp-B8h]
  float v37; // [rsp+64h] [rbp-B4h]
  float v38; // [rsp+68h] [rbp-B0h]
  float v39; // [rsp+6Ch] [rbp-ACh]
  int v40; // [rsp+70h] [rbp-A8h]
  int v41; // [rsp+74h] [rbp-A4h]

  if ( this->mDebugData && !gDisableDebugDraw )
  {
    v6 = p0->y;
    v7 = p0->z;
    line_points.x = p0->x;
    line_points.y = v6;
    line_points.z = v7;
    v8 = p1->y;
    v9 = p1->x;
    v10 = p1->z;
    v11 = (__m128)LODWORD(p1->y);
    v11.m128_f32[0] = v11.m128_f32[0] - v6;
    v12 = p1->z - v7;
    v13 = p1->x - line_points.x;
    v14 = v11;
    v15 = v11.m128_f32[0];
    v14.m128_f32[0] = v11.m128_f32[0] * v11.m128_f32[0];
    LODWORD(v16) = v11.m128_i32[0] ^ _xmm[0];
    v14.m128_f32[0] = (float)(v14.m128_f32[0] + (float)(v13 * v13)) + (float)(v12 * v12);
    LODWORD(v17) = (unsigned __int128)_mm_sqrt_ps(v14);
    v18 = (float)((float)(v13 * 15.0) * 0.0625) + line_points.x;
    *(float *)&v19 = (float)((float)(v15 * 15.0) * 0.0625) + v6;
    v27 = (float)((float)(v13 * 15.0) * 0.0625) + line_points.x;
    v28 = v19;
    v20 = (float)(v16 * v16) + (float)(v13 * v13);
    *(float *)&v21 = (float)((float)(v12 * 15.0) * 0.0625) + v7;
    v29 = v21;
    if ( v20 <= 0.0001 )
    {
      v24 = 0.0;
      v23 = v17 * 0.03125;
      v25 = 0.0;
    }
    else
    {
      v22 = (float)(v17 * 0.03125) / fsqrt(v20);
      v23 = v22 * v16;
      v24 = v22 * v13;
      v25 = v22 * 0.0;
    }
    v33 = v9;
    v34 = v8;
    v35 = v10;
    v30 = v18 + v23;
    v31 = *(float *)&v19 + v24;
    v32 = *(float *)&v21 + v25;
    v36 = v18 - v23;
    v37 = *(float *)&v19 - v24;
    v38 = *(float *)&v21 - v25;
    v39 = (float)((float)(v13 * 15.0) * 0.0625) + line_points.x;
    v40 = v19;
    v41 = v21;
    Render::DebugDrawContext::DrawLineStrip(this, &line_points, 6, colour, local_world, pre_draw_callback);
  }
}

// File Line: 824
// RVA: 0x18B70
void __fastcall Render::DebugDrawContext::DrawPoint(Render::DebugDrawContext *this, UFG::qVector3 *point, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm1_4
  UFG::qVector3 aabb_max; // [rsp+30h] [rbp-28h]
  UFG::qVector3 aabb_min; // [rsp+40h] [rbp-18h]

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      v5 = point->y;
      v6 = point->x + 0.25;
      v7 = point->z;
      aabb_min.x = point->x - 0.25;
      aabb_min.z = v7 - 0.25;
      aabb_min.y = v5 - 0.25;
      aabb_max.x = v6;
      aabb_max.y = v5 + 0.25;
      aabb_max.z = v7 + 0.25;
      Render::DebugDrawContext::DrawAABB(this, &aabb_min, &aabb_max, colour, local_world, pre_draw_callback);
    }
  }
}

// File Line: 850
// RVA: 0x17C10
void __fastcall Render::DebugDrawContext::DrawAABB(Render::DebugDrawContext *this, UFG::qVector3 *aabb_min, UFG::qVector3 *aabb_max, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qColour *v6; // rbp
  UFG::qVector3 *v7; // r14
  UFG::qVector3 *v8; // r15
  Render::DebugDrawContext *v9; // rbx
  Render::DebugData *v10; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  char *v16; // rax
  UFG::qNode<Render::DebugAABB,Render::DebugAABB> *v17; // rax
  UFG::qList<Render::DebugAABB,Render::DebugAABB,1,0> *v18; // rdx
  UFG::qNode<Render::DebugAABB,Render::DebugAABB> *v19; // rcx

  v6 = colour;
  v7 = aabb_max;
  v8 = aabb_min;
  v9 = this;
  v10 = this->mDebugData;
  if ( v10 && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v12 = UFG::qLinearAllocator::Malloc(&v10->mDebugMemory, 0x40u, 0x10u);
      v11 = (UFG::qMatrix44 *)v12;
      if ( !v12 )
      {
LABEL_10:
        v9->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v13 = local_world->v1;
      v14 = local_world->v2;
      v15 = local_world->v3;
      *(UFG::qVector4 *)v12 = local_world->v0;
      *((UFG::qVector4 *)v12 + 1) = v13;
      *((UFG::qVector4 *)v12 + 2) = v14;
      *((UFG::qVector4 *)v12 + 3) = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v16 = UFG::qLinearAllocator::Malloc(&v9->mDebugData->mDebugMemory, 0x48u, 0x10u);
    if ( v16 )
    {
      Render::DebugAABB::DebugAABB((Render::DebugAABB *)v16, v8, v7, v6, v11, pre_draw_callback);
      if ( v17 )
      {
        v18 = &v9->mDebugData->mDebugAABB;
        v19 = v18->mNode.mPrev;
        v19->mNext = v17;
        v17->mPrev = v19;
        v17->mNext = &v18->mNode;
        v18->mNode.mPrev = v17;
        return;
      }
    }
    goto LABEL_10;
  }
}

// File Line: 880
// RVA: 0x18A50
void __fastcall Render::DebugDrawContext::DrawPillar(Render::DebugDrawContext *this, UFG::qVector3 *position, float radius, float height, UFG::qColour *colour, UFG::qMatrix44 *localWorld, void (__fastcall *preDrawCallback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  float v7; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  UFG::qVector3 aabb_max; // [rsp+30h] [rbp-78h]
  UFG::qVector3 aabb_min; // [rsp+3Ch] [rbp-6Ch]

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      v7 = position->y;
      v8 = position->z;
      v9 = position->x;
      aabb_min.y = v7 - radius;
      aabb_max.x = (float)(height * 0.0) + (float)(radius + v9);
      aabb_max.z = height + (float)((float)(radius * 0.0) + v8);
      aabb_max.y = (float)(height * 0.0) + (float)(radius + v7);
      aabb_min.z = v8 - (float)(radius * 0.0);
      aabb_min.x = v9 - radius;
      Render::DebugDrawContext::DrawAABB(this, &aabb_min, &aabb_max, colour, localWorld, preDrawCallback);
    }
  }
}

// File Line: 891
// RVA: 0x18D00
void __fastcall Render::DebugDrawContext::DrawSphere(Render::DebugDrawContext *this, UFG::qVector3 *centre, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qColour *v6; // r14
  float v7; // xmm6_4
  UFG::qVector3 *v8; // rbp
  Render::DebugDrawContext *v9; // rbx
  Render::DebugData *v10; // rcx
  char *v11; // rdi
  char *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  char *v16; // rax
  char *v17; // rdx
  float v18; // xmm1_4
  float v19; // xmm2_4
  UFG::qList<Render::DebugSphere,Render::DebugSphere,1,0> *v20; // rcx
  UFG::qNode<Render::DebugSphere,Render::DebugSphere> *v21; // rax

  v6 = colour;
  v7 = radius;
  v8 = centre;
  v9 = this;
  v10 = this->mDebugData;
  if ( v10 && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v12 = UFG::qLinearAllocator::Malloc(&v10->mDebugMemory, 0x40u, 0x10u);
      v11 = v12;
      if ( !v12 )
      {
LABEL_9:
        v9->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v13 = local_world->v1;
      v14 = local_world->v2;
      v15 = local_world->v3;
      *(UFG::qVector4 *)v12 = local_world->v0;
      *((UFG::qVector4 *)v12 + 1) = v13;
      *((UFG::qVector4 *)v12 + 2) = v14;
      *((UFG::qVector4 *)v12 + 3) = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v16 = UFG::qLinearAllocator::Malloc(&v9->mDebugData->mDebugMemory, 0x40u, 0x10u);
    v17 = v16;
    if ( v16 )
    {
      *(_QWORD *)v16 = v16;
      *((_QWORD *)v16 + 1) = v16;
      v18 = v8->y;
      v19 = v8->z;
      *((_DWORD *)v16 + 7) = LODWORD(v8->x);
      *((float *)v16 + 8) = v18;
      *((float *)v16 + 9) = v19;
      *((float *)v16 + 6) = v7;
      *((_DWORD *)v16 + 10) = LODWORD(v6->r);
      *((_DWORD *)v16 + 11) = LODWORD(v6->g);
      *((_DWORD *)v16 + 12) = LODWORD(v6->b);
      *((_DWORD *)v16 + 13) = LODWORD(v6->a);
      *((_QWORD *)v16 + 2) = v11;
      *((_QWORD *)v16 + 7) = pre_draw_callback;
      v20 = &v9->mDebugData->mDebugSphere;
      v21 = v20->mNode.mPrev;
      v21->mNext = (UFG::qNode<Render::DebugSphere,Render::DebugSphere> *)v17;
      *(_QWORD *)v17 = v21;
      *((_QWORD *)v17 + 1) = v20;
      v20->mNode.mPrev = (UFG::qNode<Render::DebugSphere,Render::DebugSphere> *)v17;
      return;
    }
    goto LABEL_9;
  }
}

// File Line: 921
// RVA: 0x18500
void __fastcall Render::DebugDrawContext::DrawCylinder(Render::DebugDrawContext *this, UFG::qVector3 *min, UFG::qVector3 *max, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qVector3 *v7; // rbp
  UFG::qVector3 *v8; // r14
  Render::DebugDrawContext *v9; // rbx
  Render::DebugData *v10; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm0
  char *v16; // rax
  UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *v17; // rax
  UFG::qList<Render::DebugCylinder,Render::DebugCylinder,1,0> *v18; // rdx
  UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *v19; // rcx

  v7 = max;
  v8 = min;
  v9 = this;
  v10 = this->mDebugData;
  if ( v10 && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v12 = UFG::qLinearAllocator::Malloc(&v10->mDebugMemory, 0x40u, 0x10u);
      v11 = (UFG::qMatrix44 *)v12;
      if ( !v12 )
      {
LABEL_10:
        v9->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v13 = local_world->v1;
      v14 = local_world->v2;
      v15 = local_world->v3;
      *(UFG::qVector4 *)v12 = local_world->v0;
      *((UFG::qVector4 *)v12 + 1) = v13;
      *((UFG::qVector4 *)v12 + 2) = v14;
      *((UFG::qVector4 *)v12 + 3) = v15;
    }
    else
    {
      v11 = 0i64;
    }
    v16 = UFG::qLinearAllocator::Malloc(&v9->mDebugData->mDebugMemory, 0x50u, 0x10u);
    if ( v16 )
    {
      Render::DebugCylinder::DebugCylinder((Render::DebugCylinder *)v16, v8, v7, radius, colour, v11, pre_draw_callback);
      if ( v17 )
      {
        v18 = &v9->mDebugData->mDebugCylinder;
        v19 = v18->mNode.mPrev;
        v19->mNext = v17;
        v17->mPrev = v19;
        v17->mNext = &v18->mNode;
        v18->mNode.mPrev = v17;
        return;
      }
    }
    goto LABEL_10;
  }
}

// File Line: 961
// RVA: 0x182F0
void __fastcall Render::DebugDrawContext::DrawCircle(Render::DebugDrawContext *this, UFG::qVector3 *centre, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qVector3 normal; // [rsp+40h] [rbp-18h]

  if ( this->mDebugData )
  {
    if ( !gDisableDebugDraw )
    {
      LODWORD(normal.z) = (_DWORD)FLOAT_1_0;
      *(_QWORD *)&normal.x = 0i64;
      Render::DebugDrawContext::DrawCircle(this, centre, &normal, radius, colour, local_world, pre_draw_callback);
    }
  }
}

// File Line: 969
// RVA: 0x181E0
void __fastcall Render::DebugDrawContext::DrawCircle(Render::DebugDrawContext *this, UFG::qVector3 *centre, UFG::qVector3 *normal, const float radius, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qVector3 *v7; // rsi
  UFG::qVector3 *v8; // rbp
  Render::DebugDrawContext *v9; // rbx
  Render::DebugData *v10; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qNode<Render::DebugCircle,Render::DebugCircle> *v13; // rax
  UFG::qList<Render::DebugCircle,Render::DebugCircle,1,0> *v14; // rdx
  UFG::qNode<Render::DebugCircle,Render::DebugCircle> *v15; // rcx

  v7 = normal;
  v8 = centre;
  v9 = this;
  v10 = this->mDebugData;
  if ( v10 && !gDisableDebugDraw )
  {
    v11 = 0i64;
    if ( (!local_world || (v11 = Render::DebugData::AllocMatrix(v10, local_world)) != 0i64)
      && (v12 = UFG::qLinearAllocator::Malloc(&v9->mDebugData->mDebugMemory, 0x50u, 0x10u)) != 0i64
      && (Render::DebugCircle::DebugCircle((Render::DebugCircle *)v12, v8, v7, radius, colour, v11, pre_draw_callback),
          v13) )
    {
      v14 = &v9->mDebugData->mDebugCircle;
      v15 = v14->mNode.mPrev;
      v15->mNext = v13;
      v13->mPrev = v15;
      v13->mNext = &v14->mNode;
      v14->mNode.mPrev = v13;
    }
    else
    {
      v9->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1004
// RVA: 0x17D40
void __fastcall Render::DebugDrawContext::DrawArc(Render::DebugDrawContext *this, const float radius, const float minAngle, const float maxAngle, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  Render::DebugDrawContext *v7; // rbx
  Render::DebugData *v8; // rcx
  UFG::qMatrix44 *v9; // rdi
  char *v10; // rax
  char *v11; // rdx
  UFG::qList<Render::DebugArc,Render::DebugArc,1,0> *v12; // rcx
  UFG::qNode<Render::DebugArc,Render::DebugArc> *v13; // rax

  v7 = this;
  v8 = this->mDebugData;
  if ( v8 && !gDisableDebugDraw )
  {
    v9 = 0i64;
    if ( (!local_world || (v9 = Render::DebugData::AllocMatrix(v8, local_world)) != 0i64)
      && (v10 = UFG::qLinearAllocator::Malloc(&v7->mDebugData->mDebugMemory, 0x40u, 0x10u), (v11 = v10) != 0i64) )
    {
      *(_QWORD *)v10 = v10;
      *((_QWORD *)v10 + 1) = v10;
      *((const float *)v10 + 7) = minAngle;
      *((const float *)v10 + 8) = maxAngle;
      *((const float *)v10 + 6) = radius;
      *((_DWORD *)v10 + 9) = LODWORD(colour->r);
      *((_DWORD *)v10 + 10) = LODWORD(colour->g);
      *((_DWORD *)v10 + 11) = LODWORD(colour->b);
      *((_DWORD *)v10 + 12) = LODWORD(colour->a);
      *((_QWORD *)v10 + 2) = v9;
      *((_QWORD *)v10 + 7) = pre_draw_callback;
      v12 = &v7->mDebugData->mDebugArc;
      v13 = v12->mNode.mPrev;
      v13->mNext = (UFG::qNode<Render::DebugArc,Render::DebugArc> *)v11;
      *(_QWORD *)v11 = v13;
      *((_QWORD *)v11 + 1) = v12;
      v12->mNode.mPrev = (UFG::qNode<Render::DebugArc,Render::DebugArc> *)v11;
    }
    else
    {
      v7->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1037
// RVA: 0x188A0
void __fastcall Render::DebugDrawContext::DrawLineStrip(Render::DebugDrawContext *this, UFG::qVector3 *line_points, const int num_points, UFG::qColour *colour, UFG::qMatrix44 *local_world, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  UFG::qColour *v6; // rsi
  int v7; // ebp
  UFG::qVector3 *v8; // r14
  Render::DebugDrawContext *v9; // rbx
  Render::DebugData *v10; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // r10
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v13; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *v14; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v15; // rcx
  UFG::DrawInfo info; // [rsp+40h] [rbp-58h]

  v6 = colour;
  v7 = num_points;
  v8 = line_points;
  v9 = this;
  v10 = this->mDebugData;
  if ( v10 && !gDisableDebugDraw )
  {
    v11 = 0i64;
    if ( local_world )
    {
      v11 = Render::DebugData::AllocMatrix(v10, local_world);
      if ( !v11 )
        goto LABEL_12;
    }
    v12 = UFG::qLinearAllocator::Malloc(&v9->mDebugData->mDebugMemory, 0x60u, 0x10u);
    if ( !v12 )
      goto LABEL_12;
    info.mScale = UFG::DrawInfo::msDefault.mScale;
    info.mAlphaBlend = UFG::DrawInfo::msDefault.mAlphaBlend;
    info.mDepthBuffer = UFG::DrawInfo::msDefault.mDepthBuffer;
    info.mFaceCull = UFG::DrawInfo::msDefault.mFaceCull;
    info.mDepthBias = UFG::DrawInfo::msDefault.mDepthBias;
    info.mColour1.r = v6->r;
    info.mColour1.g = v6->g;
    info.mColour1.b = v6->b;
    info.mColour1.a = v6->a;
    info.mColour2.r = v6->r;
    info.mColour2.g = v6->g;
    info.mColour2.b = v6->b;
    info.mColour2.a = v6->a;
    info.mPreDrawCallback = pre_draw_callback;
    Render::DebugLineStrip::DebugLineStrip(
      (Render::DebugLineStrip *)v12,
      &v9->mDebugData->mDebugMemory,
      v8,
      v7,
      &info,
      v11);
    if ( !v13 )
      goto LABEL_12;
    if ( v13[1].mPrev )
    {
      v14 = &v9->mDebugData->mDebugLineStrips;
      v15 = v14->mNode.mPrev;
      v15->mNext = v13;
      v13->mPrev = v15;
      v13->mNext = &v14->mNode;
      v14->mNode.mPrev = v13;
    }
    else
    {
LABEL_12:
      v9->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1073
// RVA: 0x18760
void __fastcall Render::DebugDrawContext::DrawLineStrip(Render::DebugDrawContext *this, UFG::qVector3 *line_points, const int num_points, UFG::DrawInfo *info, UFG::qMatrix44 *local_world)
{
  UFG::DrawInfo *v5; // rbp
  int v6; // er14
  UFG::qVector3 *v7; // r15
  Render::DebugDrawContext *v8; // rbx
  Render::DebugData *v9; // rcx
  UFG::qMatrix44 *v10; // rdi
  char *v11; // rax
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  char *v15; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v16; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *v17; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v18; // rcx

  v5 = info;
  v6 = num_points;
  v7 = line_points;
  v8 = this;
  v9 = this->mDebugData;
  if ( v9 && !gDisableDebugDraw )
  {
    if ( local_world )
    {
      v11 = UFG::qLinearAllocator::Malloc(&v9->mDebugMemory, 0x40u, 0x10u);
      v10 = (UFG::qMatrix44 *)v11;
      if ( !v11 )
      {
LABEL_11:
        v8->mDebugData->mHaveExceededPool = 1;
        return;
      }
      v12 = local_world->v1;
      v13 = local_world->v2;
      v14 = local_world->v3;
      *(UFG::qVector4 *)v11 = local_world->v0;
      *((UFG::qVector4 *)v11 + 1) = v12;
      *((UFG::qVector4 *)v11 + 2) = v13;
      *((UFG::qVector4 *)v11 + 3) = v14;
    }
    else
    {
      v10 = 0i64;
    }
    v15 = UFG::qLinearAllocator::Malloc(&v8->mDebugData->mDebugMemory, 0x60u, 0x10u);
    if ( v15 )
    {
      Render::DebugLineStrip::DebugLineStrip(
        (Render::DebugLineStrip *)v15,
        &v8->mDebugData->mDebugMemory,
        v7,
        v6,
        v5,
        v10);
      if ( v16 )
      {
        if ( v16[1].mPrev )
        {
          v17 = &v8->mDebugData->mDebugLineStrips;
          v18 = v17->mNode.mPrev;
          v18->mNext = v16;
          v16->mPrev = v18;
          v16->mNext = &v17->mNode;
          v17->mNode.mPrev = v16;
          return;
        }
      }
    }
    goto LABEL_11;
  }
}

// File Line: 1099
// RVA: 0x19290
void __fastcall Render::DebugDrawContext::DrawTriStrip(Render::DebugDrawContext *this, UFG::qVector3 *tri_points, const int num_points, UFG::DrawInfo *info, UFG::qMatrix44 *local_world, bool is_screen_coords)
{
  UFG::DrawInfo *v6; // rsi
  int v7; // ebp
  UFG::qVector3 *v8; // r14
  Render::DebugDrawContext *v9; // rbx
  Render::DebugData *v10; // rcx
  UFG::qMatrix44 *v11; // rdi
  char *v12; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v13; // rax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v14; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v15; // rcx

  v6 = info;
  v7 = num_points;
  v8 = tri_points;
  v9 = this;
  v10 = this->mDebugData;
  if ( v10 && !gDisableDebugDraw )
  {
    v11 = 0i64;
    if ( (!local_world || (v11 = Render::DebugData::AllocMatrix(v10, local_world)) != 0i64)
      && (v12 = UFG::qLinearAllocator::Malloc(&v9->mDebugData->mDebugMemory, 0x68u, 0x10u)) != 0i64
      && (Render::DebugTriStrip::DebugTriStrip(
            (Render::DebugTriStrip *)v12,
            &v9->mDebugData->mDebugMemory,
            v8,
            v7,
            v6,
            v11,
            is_screen_coords),
          v13)
      && v13[5].mNext )
    {
      v14 = &v9->mDebugData->mDebugTriStrips;
      v15 = v14->mNode.mPrev;
      v15->mNext = v13;
      v13->mPrev = v15;
      v13->mNext = &v14->mNode;
      v14->mNode.mPrev = v13;
    }
    else
    {
      v9->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1125
// RVA: 0x180F0
void __fastcall Render::DebugDrawContext::DrawAxes(Render::DebugDrawContext *this, UFG::qMatrix44 *xform, float scale, bool depth_buffer, void (__fastcall *pre_draw_callback)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))
{
  bool v5; // si
  float v6; // xmm6_4
  UFG::qMatrix44 *v7; // rdi
  Render::DebugDrawContext *v8; // rbx
  Render::DebugData *v9; // rcx
  char *v10; // rax
  char *v11; // rdx
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::qList<Render::DebugAxis,Render::DebugAxis,1,0> *v15; // rcx
  UFG::qNode<Render::DebugAxis,Render::DebugAxis> *v16; // rax

  v5 = depth_buffer;
  v6 = scale;
  v7 = xform;
  v8 = this;
  v9 = this->mDebugData;
  if ( v9 && !gDisableDebugDraw )
  {
    v10 = UFG::qLinearAllocator::Malloc(&v9->mDebugMemory, 0x60u, 0x10u);
    v11 = v10;
    if ( v10 )
    {
      *(_QWORD *)v10 = v10;
      *((_QWORD *)v10 + 1) = v10;
      v12 = v7->v1;
      v13 = v7->v2;
      v14 = v7->v3;
      *((_OWORD *)v10 + 1) = v7->v0;
      *((UFG::qVector4 *)v10 + 2) = v12;
      *((UFG::qVector4 *)v10 + 3) = v13;
      *((UFG::qVector4 *)v10 + 4) = v14;
      *((float *)v10 + 20) = v6;
      v10[84] = v5;
      *((_QWORD *)v10 + 11) = pre_draw_callback;
      v15 = &v8->mDebugData->mDebugAxis;
      v16 = v15->mNode.mPrev;
      v16->mNext = (UFG::qNode<Render::DebugAxis,Render::DebugAxis> *)v11;
      *(_QWORD *)v11 = v16;
      *((_QWORD *)v11 + 1) = v15;
      v15->mNode.mPrev = (UFG::qNode<Render::DebugAxis,Render::DebugAxis> *)v11;
    }
    else
    {
      v8->mDebugData->mHaveExceededPool = 1;
    }
  }
}

// File Line: 1148
// RVA: 0x18350
void __fastcall Render::DebugDrawContext::DrawCoord(Render::DebugDrawContext *this, UFG::qMatrix44 *xform, float scale, const char *text)
{
  float v4; // xmm4_4
  float v5; // xmm3_4
  const char *v6; // rsi
  UFG::qMatrix44 *v7; // rbx
  float v8; // xmm0_4
  float v9; // xmm1_4
  Render::DebugDrawContext *v10; // rdi
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 p0; // [rsp+40h] [rbp-38h]
  UFG::qVector3 p1; // [rsp+4Ch] [rbp-2Ch]

  v4 = xform->v3.y;
  v5 = xform->v3.z;
  v6 = text;
  v7 = xform;
  v8 = scale * xform->v0.x;
  v9 = scale * xform->v0.y;
  p0.x = xform->v3.x;
  p0.y = v4;
  p0.z = v5;
  v10 = this;
  v11 = v5 + (float)(scale * xform->v0.z);
  p1.x = p0.x + v8;
  p1.y = v4 + v9;
  p1.z = v11;
  Render::DebugDrawContext::DrawLine(
    this,
    &p0,
    &p1,
    &UFG::qColour::Red,
    &UFG::qMatrix44::msIdentity,
    (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
    0);
  v12 = (float)(scale * v7->v1.y) + v7->v3.y;
  v13 = (float)(scale * v7->v1.z) + v7->v3.z;
  p1.x = (float)(scale * v7->v1.x) + v7->v3.x;
  p1.y = v12;
  p1.z = v13;
  Render::DebugDrawContext::DrawLine(
    v10,
    &p0,
    &p1,
    &UFG::qColour::Yellow,
    &UFG::qMatrix44::msIdentity,
    (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
    0);
  v14 = (float)(scale * v7->v2.x) + v7->v3.x;
  v15 = (float)(scale * v7->v2.y) + v7->v3.y;
  p1.z = (float)(scale * v7->v2.z) + v7->v3.z;
  p1.x = v14;
  p1.y = v15;
  Render::DebugDrawContext::DrawLine(
    v10,
    &p0,
    &p1,
    &UFG::qColour::Blue,
    &UFG::qMatrix44::msIdentity,
    (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))Render::gXRayDrawCallback,
    0);
  if ( v6 )
    Render::DebugDrawContext::DrawText(v10, &p0, &UFG::qColour::Green, "%s", v6);
}

// File Line: 1183
// RVA: 0x177F0
void __fastcall Render::DebugDrawContext::Clear(Render::DebugDrawContext *this)
{
  Render::DebugData *v1; // rdx
  Render::DebugDrawContext *v2; // rbx
  UFG::qList<Render::DebugAABB,Render::DebugAABB,1,0> *v3; // rax
  UFG::qList<Render::DebugLineStrip,Render::DebugLineStrip,1,0> *v4; // rax
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v5; // rax
  UFG::qList<Render::DebugRect,Render::DebugRect,1,0> *v6; // rax
  UFG::qList<Render::DebugSphere,Render::DebugSphere,1,0> *v7; // rax
  UFG::qList<Render::DebugCylinder,Render::DebugCylinder,1,0> *v8; // rax
  UFG::qList<Render::DebugCircle,Render::DebugCircle,1,0> *v9; // rax
  UFG::qList<Render::DebugArc,Render::DebugArc,1,0> *v10; // rax
  UFG::qList<Render::DebugAxis,Render::DebugAxis,1,0> *v11; // rax
  UFG::qList<Render::DebugText,Render::DebugText,1,0> *v12; // rax
  UFG::qList<Render::DebugIcon,Render::DebugIcon,1,0> *v13; // rax

  v1 = this->mDebugData;
  v2 = this;
  if ( v1 )
  {
    UFG::qLinearAllocator::Init(&v1->mDebugMemory, v1->mDebugPool, v1->mDebugPoolSize, 0i64, 0i64);
    v3 = &v2->mDebugData->mDebugAABB;
    v3->mNode.mPrev = &v3->mNode;
    v3->mNode.mNext = &v3->mNode;
    v4 = &v2->mDebugData->mDebugLineStrips;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
    v5 = &v2->mDebugData->mDebugTriStrips;
    v5->mNode.mPrev = &v5->mNode;
    v5->mNode.mNext = &v5->mNode;
    v6 = &v2->mDebugData->mDebugRects;
    v6->mNode.mPrev = &v6->mNode;
    v6->mNode.mNext = &v6->mNode;
    v7 = &v2->mDebugData->mDebugSphere;
    v7->mNode.mPrev = &v7->mNode;
    v7->mNode.mNext = &v7->mNode;
    v8 = &v2->mDebugData->mDebugCylinder;
    v8->mNode.mPrev = &v8->mNode;
    v8->mNode.mNext = &v8->mNode;
    v9 = &v2->mDebugData->mDebugCircle;
    v9->mNode.mPrev = &v9->mNode;
    v9->mNode.mNext = &v9->mNode;
    v10 = &v2->mDebugData->mDebugArc;
    v10->mNode.mPrev = &v10->mNode;
    v10->mNode.mNext = &v10->mNode;
    v11 = &v2->mDebugData->mDebugAxis;
    v11->mNode.mPrev = &v11->mNode;
    v11->mNode.mNext = &v11->mNode;
    v12 = &v2->mDebugData->mDebugTextLines;
    v12->mNode.mPrev = &v12->mNode;
    v12->mNode.mNext = &v12->mNode;
    v13 = &v2->mDebugData->mDebugIcons;
    v13->mNode.mPrev = &v13->mNode;
    v13->mNode.mNext = &v13->mNode;
    v2->mDebugData->mHaveExceededPool = 0;
    UFG::qLinearAllocator::Reset(&v2->mDebugData->mDebugMemory);
  }
}

// File Line: 1208
// RVA: 0x17A70
bool __fastcall Render::CompareTristrips(Render::DebugTriStrip *a, Render::DebugTriStrip *b)
{
  return b->mSortMetric < a->mSortMetric;
}

// File Line: 1213
// RVA: 0x193A0
void __fastcall Render::DebugDrawContext::Flush(Render::DebugDrawContext *this)
{
  Render::DebugDrawContext *v1; // rbx
  float v2; // xmm9_4
  signed int v3; // eax
  UFG::qNode<Render::DebugRect,Render::DebugRect> *v4; // rdi
  float i; // xmm10_4
  Render::DebugData *v6; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v7; // rdi
  int v8; // eax
  unsigned int v9; // er10
  signed __int64 v10; // r9
  __int64 v11; // rcx
  unsigned __int64 v12; // r8
  float v13; // xmm2_4
  float v14; // xmm3_4
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v15; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v16; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v17; // rax
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v18; // rax
  signed __int64 v19; // rcx
  signed __int64 v20; // rdx
  UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *v21; // rax
  float v22; // xmm1_4
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *j; // rdx
  float *v24; // rcx
  int v25; // eax
  signed __int64 v26; // r8
  signed __int64 v27; // r10
  __int64 v28; // rcx
  unsigned __int64 v29; // r9
  float v30; // xmm2_4
  float v31; // xmm3_4
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v32; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v33; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v34; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v35; // rax
  signed __int64 v36; // rcx
  signed __int64 v37; // r8
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v38; // rax
  float v39; // xmm1_4
  float *v40; // r9
  float v41; // xmm6_4
  float v42; // xmm7_4
  float v43; // xmm5_4
  float v44; // xmm3_4
  float v45; // xmm6_4
  float v46; // xmm2_4
  float v47; // xmm7_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  Render::DebugData *v50; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v51; // rdi
  UFG::qVector3 *v52; // rdx
  UFG::qNode<Render::DebugAABB,Render::DebugAABB> *k; // rdi
  UFG::qNode<Render::DebugSphere,Render::DebugSphere> *l; // rdi
  UFG::qNode<Render::DebugCylinder,Render::DebugCylinder> *m; // rdi
  UFG::qNode<Render::DebugCircle,Render::DebugCircle> *n; // rdi
  Render::DebugData *v57; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v58; // rdi
  Render::View *v59; // rcx
  float v60; // xmm0_4
  UFG::qNode<Render::DebugAxis,Render::DebugAxis> *ii; // rdi
  Render::DebugData *v62; // rcx
  UFG::qNode<Render::DebugText,Render::DebugText> *v63; // rdi
  Render::Font *v64; // rsi
  __int128 v65; // xmm6
  signed int v66; // eax
  UFG::qMatrix44 *v67; // r8
  int v68; // ecx
  float v69; // xmm1_4
  float v70; // xmm1_4
  int v71; // ecx
  __m128i v72; // xmm0
  __m128i v73; // xmm0
  UFG::qNode<Render::DebugIcon,Render::DebugIcon> *jj; // rdi
  int v75; // ecx
  int v76; // eax
  unsigned int v77; // edx
  signed __int64 height; // [rsp+20h] [rbp-D0h]
  UFG::qColour *colour_left; // [rsp+28h] [rbp-C8h]
  UFG::qColour *colour_right; // [rsp+30h] [rbp-C0h]
  __int128 v81; // [rsp+40h] [rbp-B0h]
  UFG::DrawInfo info; // [rsp+50h] [rbp-A0h]
  int w; // [rsp+110h] [rbp+20h]
  void *retaddr; // [rsp+118h] [rbp+28h]
  UFG::qVector2 viewport_scale; // [rsp+120h] [rbp+30h]

  v1 = this;
  if ( this->mDebugData && !gDisableDebugDraw )
  {
    v2 = (float)(signed int)Render::View::GetTargetWidth(this->mView);
    v3 = Render::View::GetTargetHeight(v1->mView);
    v4 = v1->mDebugData->mDebugRects.mNode.mNext;
    for ( i = (float)v3; v4 != &v1->mDebugData->mDebugRects.mNode; v4 = v4->mNext )
      Render::View::DrawGradient(
        v1->mView,
        (signed int)*(float *)&v4[1].mPrev,
        (signed int)*((float *)&v4[1].mPrev + 1),
        (signed int)*(float *)&v4[1].mNext,
        (signed int)*((float *)&v4[1].mNext + 1),
        (UFG::qColour *)&v4[2],
        (UFG::qColour *)&v4[2]);
    v6 = v1->mDebugData;
    v7 = v6->mDebugLineStrips.mNode.mNext;
    if ( v7 != (UFG::qNode<Render::DebugLineStrip,Render::DebugLineStrip> *)&v6->mDebugLineStrips )
    {
      do
      {
        if ( v7[1].mPrev )
        {
          v8 = (int)v7[2].mPrev;
          v9 = (unsigned __int16)v8;
          if ( v8 & 0x10000 )
          {
            v10 = 0i64;
            if ( (signed __int64)(unsigned __int16)v8 >= 4 )
            {
              v11 = 0i64;
              v12 = (((unsigned __int64)(unsigned __int16)v8 - 4) >> 2) + 1;
              v13 = 1.0 / v2;
              v14 = 1.0 / i;
              v10 = 4 * v12;
              do
              {
                v15 = v7[1].mPrev;
                v11 += 3i64;
                *(float *)&v15[v11 - 3].mPrev = v13 * *(float *)&v15[v11 - 3].mPrev;
                *((float *)&v15[v11 - 2] - 3) = v14 * *((float *)&v15[v11 - 2] - 3);
                v16 = v7[1].mPrev;
                *((float *)&v16[v11 - 2] - 1) = v13 * *((float *)&v16[v11 - 2] - 1);
                *(float *)&v16[v11 - 2].mPrev = v14 * *(float *)&v16[v11 - 2].mPrev;
                v17 = v7[1].mPrev;
                *((float *)&v17[v11 - 1] - 2) = v13 * *((float *)&v17[v11 - 1] - 2);
                *((float *)&v17[v11 - 1] - 1) = v14 * *((float *)&v17[v11 - 1] - 1);
                v18 = v7[1].mPrev;
                *((float *)&v18[v11] - 3) = v13 * *((float *)&v18[v11] - 3);
                *((float *)&v18[v11] - 2) = v14 * *((float *)&v18[v11] - 2);
                --v12;
              }
              while ( v12 );
            }
            if ( v10 < v9 )
            {
              v19 = 12 * v10;
              v20 = v9 - v10;
              do
              {
                v21 = v7[1].mPrev;
                v19 += 12i64;
                v22 = (float)(1.0 / i) * *(float *)((char *)v21 + v19 - 8);
                *(float *)((char *)v21 + v19 - 12) = (float)(1.0 / v2) * *(float *)((char *)v21 + v19 - 12);
                *(float *)((char *)v21 + v19 - 8) = v22;
                --v20;
              }
              while ( v20 );
            }
          }
          if ( !(v1->mFeatureFlags & 2) )
            LOBYTE(v7[5].mPrev) = 0;
          Render::View::DrawDebugPrimLineStrip(
            v1->mView,
            (UFG::qVector3 *)v7[1].mPrev,
            v9,
            (UFG::DrawInfo *)&v7[2].mNext,
            (UFG::qMatrix44 *)v7[1].mNext);
        }
        v7 = v7->mNext;
      }
      while ( v7 != &v1->mDebugData->mDebugLineStrips.mNode );
    }
    for ( j = v1->mDebugData->mDebugTriStrips.mNode.mNext; j != &v1->mDebugData->mDebugTriStrips.mNode; j = j->mNext )
    {
      v24 = (float *)j[5].mNext;
      v25 = (int)j[1].mPrev;
      if ( v24 && (_WORD)v25 )
      {
        LODWORD(j[6].mPrev) = 0;
        v26 = (unsigned __int16)v25;
        if ( v25 & 0x10000 )
        {
          v27 = 0i64;
          if ( (signed __int64)(unsigned __int16)v25 >= 4 )
          {
            v28 = 0i64;
            v29 = (((unsigned __int64)(unsigned __int16)v25 - 4) >> 2) + 1;
            v30 = 1.0 / v2;
            v31 = 1.0 / i;
            v27 = 4 * v29;
            do
            {
              v32 = j[5].mNext;
              v28 += 3i64;
              *(float *)&v32[v28 - 3].mPrev = v30 * *(float *)&v32[v28 - 3].mPrev;
              *((float *)&v32[v28 - 2] - 3) = v31 * *((float *)&v32[v28 - 2] - 3);
              v33 = j[5].mNext;
              *((float *)&v33[v28 - 2] - 1) = v30 * *((float *)&v33[v28 - 2] - 1);
              *(float *)&v33[v28 - 2].mPrev = v31 * *(float *)&v33[v28 - 2].mPrev;
              v34 = j[5].mNext;
              *((float *)&v34[v28 - 1] - 2) = v30 * *((float *)&v34[v28 - 1] - 2);
              *((float *)&v34[v28 - 1] - 1) = v31 * *((float *)&v34[v28 - 1] - 1);
              v35 = j[5].mNext;
              *((float *)&v35[v28] - 3) = v30 * *((float *)&v35[v28] - 3);
              *((float *)&v35[v28] - 2) = v31 * *((float *)&v35[v28] - 2);
              --v29;
            }
            while ( v29 );
          }
          if ( v27 < v26 )
          {
            v36 = 12 * v27;
            v37 = v26 - v27;
            do
            {
              v38 = j[5].mNext;
              v36 += 12i64;
              v39 = (float)(1.0 / i) * *(float *)((char *)v38 + v36 - 8);
              *(float *)((char *)v38 + v36 - 12) = (float)(1.0 / v2) * *(float *)((char *)v38 + v36 - 12);
              *(float *)((char *)v38 + v36 - 8) = v39;
              --v37;
            }
            while ( v37 );
          }
        }
        else
        {
          v40 = (float *)j[5].mPrev;
          if ( v40 )
          {
            if ( (signed int)(unsigned __int16)v25 > 0 )
            {
              do
              {
                v41 = v24[1];
                v42 = (float)((float)((float)(v41 * v40[4]) + (float)(*v24 * *v40)) + (float)(v24[2] * v40[8]))
                    + v40[12];
                v43 = (float)((float)((float)(v24[1] * v40[5]) + (float)(*v24 * v40[1])) + (float)(v24[2] * v40[9]))
                    + v40[13];
                v44 = (float)((float)((float)(v24[1] * v40[6]) + (float)(*v24 * v40[2])) + (float)(v24[2] * v40[10]))
                    + v40[14];
                v45 = (float)((float)((float)(v41 * v40[7]) + (float)(*v24 * v40[3])) + (float)(v24[2] * v40[11]))
                    + v40[15];
                v46 = (float)(v42 * v1->mView->mWorldViewProjection.v0.z)
                    + (float)(v43 * v1->mView->mWorldViewProjection.v1.z);
                v47 = (float)((float)((float)(v42 * v1->mView->mWorldViewProjection.v0.w)
                                    + (float)(v43 * v1->mView->mWorldViewProjection.v1.w))
                            + (float)(v44 * v1->mView->mWorldViewProjection.v2.w))
                    + (float)(v45 * v1->mView->mWorldViewProjection.v3.w);
                v48 = (float)(v46 + (float)(v44 * v1->mView->mWorldViewProjection.v2.z))
                    + (float)(v45 * v1->mView->mWorldViewProjection.v3.z);
                if ( v47 != 0.0 )
                  *(float *)&j[6].mPrev = (float)(v48 / v47) + *(float *)&j[6].mPrev;
                v24 += 3;
                --v26;
              }
              while ( v26 );
            }
            v49 = *(float *)&j[6].mPrev / (float)(unsigned __int16)v25;
            *(float *)&j[6].mPrev = v49;
            if ( BYTE4(j[6].mPrev) )
              *(float *)&j[6].mPrev = v49 - 1.0;
          }
        }
        if ( !(v1->mFeatureFlags & 2) )
          LOBYTE(j[4].mPrev) = 0;
      }
    }
    UFG::qList<UFG::qPointerNode<UFG::VoiceProfile>,UFG::qPointerNode<UFG::VoiceProfile>,1,0>::MergeSort(
      &v1->mDebugData->mDebugTriStrips,
      Render::CompareTristrips);
    v50 = v1->mDebugData;
    v51 = v50->mDebugTriStrips.mNode.mNext;
    if ( v51 != (UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *)&v50->mDebugTriStrips )
    {
      do
      {
        v52 = (UFG::qVector3 *)v51[5].mNext;
        if ( v52 && LOWORD(v51[1].mPrev) )
          Render::View::DrawDebugPrimTriStrip(
            v1->mView,
            v52,
            LOWORD(v51[1].mPrev),
            (UFG::DrawInfo *)&v51[1].mNext,
            (UFG::qMatrix44 *)v51[5].mPrev);
        v51 = v51->mNext;
      }
      while ( v51 != &v1->mDebugData->mDebugTriStrips.mNode );
    }
    for ( k = v1->mDebugData->mDebugAABB.mNode.mNext; k != &v1->mDebugData->mDebugAABB.mNode; k = k->mNext )
    {
      colour_left = (UFG::qColour *)k[4].mPrev;
      height = (signed __int64)k[1].mPrev;
      Render::View::DrawDebugPrimAABB(
        v1->mView,
        (UFG::qVector3 *)&k[2].mNext,
        (UFG::qVector3 *)((char *)&k[3].mPrev + 4),
        (UFG::qColour *)&k[1].mNext);
    }
    for ( l = v1->mDebugData->mDebugSphere.mNode.mNext; l != &v1->mDebugData->mDebugSphere.mNode; l = l->mNext )
      Render::View::DrawDebugPrimSphere(
        v1->mView,
        (UFG::qVector3 *)((char *)&l[1].mNext + 4),
        *(const float *)&l[1].mNext,
        (UFG::qColour *)&l[2].mNext,
        (UFG::qMatrix44 *)l[1].mPrev,
        (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))l[3].mNext);
    for ( m = v1->mDebugData->mDebugCylinder.mNode.mNext; m != &v1->mDebugData->mDebugCylinder.mNode; m = m->mNext )
    {
      colour_right = (UFG::qColour *)m[4].mNext;
      colour_left = (UFG::qColour *)m[1].mPrev;
      height = (signed __int64)&m[3].mPrev + 4;
      Render::View::DrawDebugPrimCylinder(
        v1->mView,
        (UFG::qVector3 *)&m[1].mNext,
        (UFG::qVector3 *)((char *)&m[2].mPrev + 4),
        *(const float *)&m[3].mPrev);
    }
    for ( n = v1->mDebugData->mDebugCircle.mNode.mNext; n != &v1->mDebugData->mDebugCircle.mNode; n = n->mNext )
      Render::View::DrawDebugPrimCircle(
        v1->mView,
        (UFG::qVector3 *)((char *)&n[1].mNext + 4),
        (UFG::qVector3 *)&n[2].mNext,
        *(const float *)&n[1].mNext,
        (UFG::qColour *)((char *)&n[3].mPrev + 4),
        (UFG::qMatrix44 *)n[1].mPrev,
        (void (__fastcall *)(Illusion::Material *, Render::View *, Illusion::StateValues *, Illusion::Primitive *, Illusion::StateArgs *))n[4].mNext);
    v57 = v1->mDebugData;
    *(_WORD *)&info.mDepthBuffer = 257;
    info.mColour1 = UFG::qColour::White;
    info.mDepthBias = 0;
    *(_QWORD *)&info.mScale = 0i64;
    v57 = (Render::DebugData *)((char *)v57 + 176);
    info.mColour2 = UFG::qColour::White;
    v58 = v57->mDebugFontHandle.mNext;
    if ( v58 != (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v57 )
    {
      do
      {
        v59 = v1->mView;
        info.mColour1.r = *((float *)&v58[2].mPrev + 1);
        info.mColour1.g = *(float *)&v58[2].mNext;
        info.mColour1.b = *((float *)&v58[2].mNext + 1);
        info.mColour1.a = *(float *)&v58[3].mPrev;
        info.mColour2.r = *((float *)&v58[2].mPrev + 1);
        info.mColour2.g = *(float *)&v58[2].mNext;
        info.mColour2.b = *((float *)&v58[2].mNext + 1);
        info.mColour2.a = *(float *)&v58[3].mPrev;
        v60 = *(float *)&v58[1].mNext;
        info.mAlphaBlend = -1551679522;
        info.mScale = v60 * 2.0;
        *(_QWORD *)&info.mScale = v58[3].mNext;
        Render::View::DrawArcSolid(
          v59,
          (UFG::qMatrix44 *)v58[1].mPrev,
          &info,
          *((float *)&v58[1].mNext + 1),
          *(float *)&v58[2].mPrev,
          0x14u);
        v58 = v58->mNext;
      }
      while ( v58 != (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v1->mDebugData->mDebugArc );
    }
    for ( ii = v1->mDebugData->mDebugAxis.mNode.mNext; ii != &v1->mDebugData->mDebugAxis.mNode; ii = ii->mNext )
    {
      height = (signed __int64)ii[5].mNext;
      Render::View::DrawAxes(v1->mView, (UFG::qMatrix44 *)&ii[1], *(float *)&ii[5].mPrev, BYTE4(ii[5].mPrev));
    }
    v62 = v1->mDebugData;
    v63 = v62->mDebugTextLines.mNode.mNext;
    if ( v63 != (UFG::qNode<Render::DebugText,Render::DebugText> *)&v62->mDebugTextLines )
    {
      while ( 1 )
      {
        v64 = (Render::Font *)v63[1].mNext[1].mPrev;
        if ( !v64 )
          v64 = (Render::Font *)v62->mDebugFontHandle.mData;
        if ( LODWORD(v63[3].mPrev) )
        {
          v65 = COERCE_UNSIGNED_INT((float)(signed int)Render::View::GetTargetHeight(v1->mView));
          v66 = Render::View::GetTargetWidth(v1->mView);
          v67 = (UFG::qMatrix44 *)v1->mView;
          LODWORD(viewport_scale.y) = v65;
          viewport_scale.x = (float)v66;
          UFG::qGetScreenCoord((UFG::qVector3 *)&v81, (UFG::qVector3 *)&v63[3].mNext, v67 + 4, &viewport_scale, 0i64);
          if ( HIDWORD(v63[3].mPrev) != 9 )
          {
            Render::Font::Measure(v64, &w, (int *)&retaddr, (const char *)v63[1].mPrev);
            v68 = HIDWORD(v63[3].mPrev);
            if ( v68 & 4 )
            {
              v69 = *(float *)&v81 - (float)w;
              goto LABEL_65;
            }
            if ( v68 & 2 )
            {
              v69 = *(float *)&v81 + (float)(w / -2);
LABEL_65:
              *(float *)&v81 = v69;
            }
            if ( v68 & 0x20 )
            {
              v70 = *((float *)&v81 + 1) - (float)(signed int)retaddr;
              goto LABEL_70;
            }
            if ( v68 & 0x10 )
            {
              v70 = *((float *)&v81 + 1) + (float)((signed int)retaddr / -2);
LABEL_70:
              *((float *)&v81 + 1) = v70;
            }
          }
          if ( *((float *)&v81 + 2) > 0.0 && *((float *)&v81 + 2) < 1.0 )
            Render::Font::Print(
              v64,
              v1->mView,
              (signed int)*(float *)&v81,
              (signed int)*((float *)&v81 + 1),
              (UFG::qColour *)&v63[2],
              (const char *)v63[1].mPrev,
              colour_right);
          goto LABEL_86;
        }
        if ( HIDWORD(v63[3].mPrev) == 9 )
          goto LABEL_85;
        Render::Font::Measure(v64, &w, (int *)&retaddr, (const char *)v63[1].mPrev, height, colour_left, colour_right);
        v71 = HIDWORD(v63[3].mPrev);
        if ( v71 & 4 )
          break;
        if ( v71 & 2 )
        {
          v72 = _mm_cvtsi32_si128(w / 2);
          goto LABEL_79;
        }
LABEL_80:
        if ( v71 & 0x20 )
        {
          v73 = _mm_cvtsi32_si128((unsigned int)retaddr);
LABEL_84:
          *((float *)&v63[3].mNext + 1) = *((float *)&v63[3].mNext + 1) - COERCE_FLOAT(_mm_cvtepi32_ps(v73));
          goto LABEL_85;
        }
        if ( v71 & 0x10 )
        {
          v73 = _mm_cvtsi32_si128((signed int)retaddr / 2);
          goto LABEL_84;
        }
LABEL_85:
        Render::Font::Print(
          v64,
          v1->mView,
          (signed int)*(float *)&v63[3].mNext,
          (signed int)*((float *)&v63[3].mNext + 1),
          (UFG::qColour *)&v63[2],
          (const char *)v63[1].mPrev,
          colour_right);
LABEL_86:
        v62 = v1->mDebugData;
        v63 = v63->mNext;
        if ( v63 == (UFG::qNode<Render::DebugText,Render::DebugText> *)&v62->mDebugTextLines )
          goto LABEL_87;
      }
      v72 = _mm_cvtsi32_si128(w);
LABEL_79:
      *(float *)&v63[3].mNext = *(float *)&v63[3].mNext - COERCE_FLOAT(_mm_cvtepi32_ps(v72));
      goto LABEL_80;
    }
LABEL_87:
    for ( jj = v1->mDebugData->mDebugIcons.mNode.mNext; jj != &v1->mDebugData->mDebugIcons.mNode; jj = jj->mNext )
    {
      v75 = (signed int)*((float *)&jj[1].mNext + 1);
      v76 = (signed int)*(float *)&jj[2].mPrev;
      v77 = (unsigned int)jj[1].mPrev;
      v81 = *(__int128 *)((char *)&jj[2] + 4);
      Render::View::DrawIcon(
        v1->mView,
        v77,
        (signed int)*((float *)&jj[1].mPrev + 1),
        (signed int)*(float *)&jj[1].mNext,
        v75,
        v76,
        (UFG::qColour *)&v81,
        0xA3833FDE);
    }
    if ( !(v1->mFeatureFlags & 1) )
      Render::DebugDrawContext::Clear(v1);
  }
}

// File Line: 1442
// RVA: 0x1A000
void __fastcall Render::DebugDrawManager::Init(Render::DebugDrawManager::InitInfo *init_info)
{
  Render::DebugDrawManager::InitInfo *v1; // rbx
  Render::DebugDrawManager *v2; // rax

  v1 = init_info;
  v2 = (Render::DebugDrawManager *)UFG::qMalloc(0x10ui64, "DebugDrawManager", 0i64);
  if ( v2 )
  {
    v2->mContexts.mNode.mPrev = &v2->mContexts.mNode;
    v2->mContexts.mNode.mNext = &v2->mContexts.mNode;
  }
  Render::DebugDrawManager::mInstance = v2;
  Render::DebugDrawManager::CreateContext(v2, 0, v1->mPersistentMainSize, 3u);
  Render::DebugDrawManager::CreateContext(Render::DebugDrawManager::mInstance, 1u, v1->mPersistentOverlaySize, 1u);
  Render::DebugDrawManager::CreateContext(Render::DebugDrawManager::mInstance, 2u, v1->mMainSize, 2u);
  Render::DebugDrawManager::CreateContext(Render::DebugDrawManager::mInstance, 3u, v1->mOverlaySize, 0);
}

// File Line: 1463
// RVA: 0x19FD0
Render::DebugDrawManager *__fastcall Render::DebugDrawManager::GetContext(Render::DebugDrawManager *this, unsigned int uid)
{
  Render::DebugDrawManager *result; // rax

  result = (Render::DebugDrawManager *)this->mContexts.mNode.mNext;
  if ( result == this )
    return 0i64;
  while ( LODWORD(result[1].mContexts.mNode.mPrev) != uid )
  {
    result = (Render::DebugDrawManager *)result->mContexts.mNode.mNext;
    if ( result == this )
      return 0i64;
  }
  return result;
}

// File Line: 1478
// RVA: 0x17A80
UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *__fastcall Render::DebugDrawManager::CreateContext(Render::DebugDrawManager *this, unsigned int uid, int mem_size, unsigned int context_feature_flags)
{
  unsigned int v4; // edi
  int v5; // er14
  unsigned int v6; // ebp
  Render::DebugDrawManager *v7; // rsi
  char *v8; // rax
  char *v9; // rbx
  __int64 v10; // rdi
  char *v11; // rax
  __int64 v12; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v13; // rcx

  v4 = context_feature_flags;
  v5 = mem_size;
  v6 = uid;
  v7 = this;
  v8 = UFG::qMalloc(0x38ui64, "DebugDrawContext", 0i64);
  v9 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v8;
    *((_QWORD *)v8 + 1) = v8;
    *((_DWORD *)v8 + 4) = v6;
    *((_DWORD *)v8 + 5) = v4;
    v10 = 0i64;
    *((_QWORD *)v8 + 3) = 0i64;
    *((_QWORD *)v8 + 4) = 0i64;
    *((_QWORD *)v8 + 5) = 0i64;
  }
  else
  {
    v10 = 0i64;
    v9 = 0i64;
  }
  v11 = UFG::qMalloc(0x200ui64, "ViewDebugContext.DebugData", 0x8000ui64);
  if ( v11 )
  {
    Render::DebugData::DebugData((Render::DebugData *)v11, v5);
    v10 = v12;
  }
  *((_QWORD *)v9 + 5) = v10;
  v13 = v7->mContexts.mNode.mPrev;
  v13->mNext = (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)v9;
  *(_QWORD *)v9 = v13;
  *((_QWORD *)v9 + 1) = v7;
  v7->mContexts.mNode.mPrev = (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)v9;
  return (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)v9;
}

// File Line: 1490
// RVA: 0x1A0B0
void __fastcall Render::DebugDrawManager::SetContextsTargetSize(Render::DebugDrawManager *this, int width, int height, unsigned int feature_mask, unsigned int feature_ref)
{
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *i; // rax

  for ( i = this->mContexts.mNode.mNext;
        i != (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)this;
        i = i->mNext )
  {
    if ( (feature_mask & HIDWORD(i[1].mPrev)) == feature_ref )
    {
      LODWORD(i[2].mPrev) = width;
      HIDWORD(i[2].mPrev) = height;
    }
  }
}

// File Line: 1503
// RVA: 0x19F60
void __fastcall Render::DebugDrawManager::FlushContexts(Render::DebugDrawManager *this, Render::View *view, unsigned int feature_mask, unsigned int feature_ref)
{
  Render::DebugDrawContext *v4; // rbx
  unsigned int v5; // esi
  unsigned int v6; // ebp
  Render::View *v7; // r14
  Render::DebugDrawManager *i; // rdi

  v4 = (Render::DebugDrawContext *)this->mContexts.mNode.mNext;
  v5 = feature_ref;
  v6 = feature_mask;
  v7 = view;
  for ( i = this; v4 != (Render::DebugDrawContext *)i; v4 = (Render::DebugDrawContext *)v4->mNext )
  {
    if ( (v6 & v4->mFeatureFlags) == v5 )
    {
      v4->mView = v7;
      Render::DebugDrawContext::Flush(v4);
      v4->mView = 0i64;
    }
  }
}

// File Line: 1518
// RVA: 0x17910
void __fastcall Render::DebugDrawManager::ClearContexts(Render::DebugDrawManager *this, unsigned int feature_mask, unsigned int feature_ref)
{
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v3; // rbx
  unsigned int v4; // esi
  unsigned int v5; // ebp
  Render::DebugDrawManager *i; // rdi
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v7; // rdx
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v8; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v9; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v10; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v11; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v12; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v13; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v14; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v15; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v16; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v17; // rax
  UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *v18; // rax

  v3 = this->mContexts.mNode.mNext;
  v4 = feature_ref;
  v5 = feature_mask;
  for ( i = this; v3 != (UFG::qNode<Render::DebugDrawContext,Render::DebugDrawContext> *)i; v3 = v3->mNext )
  {
    if ( (v5 & HIDWORD(v3[1].mPrev)) == v4 )
    {
      v7 = v3[2].mNext;
      if ( v7 )
      {
        UFG::qLinearAllocator::Init(
          (UFG::qLinearAllocator *)&v7[16],
          (char *)v7[13].mNext,
          LODWORD(v7[24].mPrev),
          0i64,
          0i64);
        v8 = v3[2].mNext + 7;
        v8->mPrev = v8;
        v8->mNext = v8;
        v9 = v3[2].mNext + 5;
        v9->mPrev = v9;
        v9->mNext = v9;
        v10 = v3[2].mNext + 6;
        v10->mPrev = v10;
        v10->mNext = v10;
        v11 = v3[2].mNext + 3;
        v11->mPrev = v11;
        v11->mNext = v11;
        v12 = v3[2].mNext + 8;
        v12->mPrev = v12;
        v12->mNext = v12;
        v13 = v3[2].mNext + 9;
        v13->mPrev = v13;
        v13->mNext = v13;
        v14 = v3[2].mNext + 10;
        v14->mPrev = v14;
        v14->mNext = v14;
        v15 = v3[2].mNext + 11;
        v15->mPrev = v15;
        v15->mNext = v15;
        v16 = v3[2].mNext + 12;
        v16->mPrev = v16;
        v16->mNext = v16;
        v17 = v3[2].mNext + 2;
        v17->mPrev = v17;
        v17->mNext = v17;
        v18 = v3[2].mNext + 4;
        v18->mPrev = v18;
        v18->mNext = v18;
        LODWORD(v3[2].mNext[13].mPrev) = 0;
        UFG::qLinearAllocator::Reset((UFG::qLinearAllocator *)&v3[2].mNext[16]);
      }
    }
  }
}

// File Line: 1536
// RVA: 0x1A0E0
void __fastcall Render::gXRayDrawCallback(Illusion::Material *material, Render::View *view, Illusion::StateValues *state_values, Illusion::Primitive *primitive)
{
  unsigned int v4; // esi
  _WORD *v5; // rdi
  Illusion::Primitive *v6; // rbp
  Render::View *v7; // r14
  Illusion::Material *v8; // rbx
  __int64 v9; // rax
  _WORD *v10; // rax
  __int64 v11; // rax
  _WORD *v12; // rax
  __int64 v13; // rax
  _WORD *v14; // rax
  __int64 v15; // rax

  v4 = *(_DWORD *)&material[2].mDebugName[28];
  v5 = 0i64;
  v6 = primitive;
  v7 = view;
  v8 = material;
  if ( v4 != 1660426324 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&material[2].mDebugName[4],
      *((_DWORD *)&material[2].0 + 22),
      0x62F81854u);
    v9 = v8->mMaterialUser.mOffset;
    if ( v9 )
      v10 = (_WORD *)((char *)&v8->mMaterialUser + v9);
    else
      v10 = 0i64;
    *v10 |= 0x20u;
  }
  if ( v8[2].mNode.mUID != -1551679522 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v8[2],
      (unsigned int)v8[2].mResourceHandles.mNode.mPrev,
      0xA3833FDE);
    v11 = v8->mMaterialUser.mOffset;
    if ( v11 )
      v12 = (_WORD *)((char *)&v8->mMaterialUser + v11);
    else
      v12 = 0i64;
    *v12 |= 0x20u;
  }
  Illusion::SubmitContext::Draw(v7->mSubmitContext, v6, v8);
  if ( *(_DWORD *)&v8[2].mDebugName[28] != v4 )
  {
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8[2].mDebugName[4], *((_DWORD *)&v8[2].0 + 22), v4);
    v13 = v8->mMaterialUser.mOffset;
    if ( v13 )
      v14 = (_WORD *)((char *)&v8->mMaterialUser + v13);
    else
      v14 = 0i64;
    *v14 |= 0x20u;
  }
  if ( v8[2].mNode.mUID != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v8[2],
      (unsigned int)v8[2].mResourceHandles.mNode.mPrev,
      0x2782CCE6u);
    v15 = v8->mMaterialUser.mOffset;
    if ( v15 )
      v5 = (_WORD *)((char *)&v8->mMaterialUser + v15);
    *v5 |= 0x20u;
  }
}

