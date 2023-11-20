// File Line: 26
// RVA: 0x1494D30
__int64 dynamic_initializer_for__AudioTrackSurfaceDetection::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AudioTrackSurfaceDetection", 0xFFFFFFFF);
  AudioTrackSurfaceDetection::sClassNameUID = result;
  return result;
}

// File Line: 40
// RVA: 0x2DE0E0
void __fastcall AudioTrackSurfaceDetection::AudioTrackSurfaceDetection(AudioTrackSurfaceDetection *this)
{
  AudioTrackSurfaceDetection *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AudioTrackSurfaceDetection::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSurfaceDetection>::`vftable';
  v1->m_RtpcVal = 0.0;
  v1->m_playPercent = 100.0;
  *(_QWORD *)&v1->m_audioTagId[4] = 0i64;
  *(_QWORD *)&v1->m_audioTagId[2] = 0i64;
  *(_QWORD *)v1->m_audioTagId = 0i64;
  *(_QWORD *)&v1->m_audioTagUID[4] = 0i64;
  *(_QWORD *)&v1->m_audioTagUID[2] = 0i64;
  *(_QWORD *)v1->m_audioTagUID = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSurfaceDetection::`vftable';
  *(_QWORD *)&v1->m_Bone = 8i64;
}

// File Line: 45
// RVA: 0x2E3550
void __fastcall AudioTrackSurfaceDetection::~AudioTrackSurfaceDetection(AudioTrackSurfaceDetection *this)
{
  AudioTrackSurfaceDetection *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSurfaceDetection::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 50
// RVA: 0x301CC0
UFG::qSymbolUC *__fastcall AudioTrackSurfaceDetection::GetBoneUID(AudioTrackSurfaceDetection *this, UFG::qSymbolUC *result)
{
  UFG::qSymbolUC *v2; // rbx
  __int64 v3; // rdx

  v2 = result;
  if ( (signed int)gAttackCollisionEnum.m_enumLists.size <= 0 )
    v3 = 0i64;
  else
    v3 = *((_QWORD *)gAttackCollisionEnum.m_enumLists.p + 3);
  UFG::qSymbolUC::create_from_string(v2, *(const char **)(*(_QWORD *)(v3 + 16) + 8i64 * (unsigned int)this->m_Bone));
  return v2;
}

// File Line: 71
// RVA: 0x1495B50
__int64 dynamic_initializer_for__PoliceScannerAudioEventTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PoliceScannerAudioEventTrack", 0xFFFFFFFF);
  PoliceScannerAudioEventTrack::sClassNameUID = result;
  return result;
}

// File Line: 96
// RVA: 0x2E3F40
void __fastcall DialogueTrackBase::~DialogueTrackBase(DialogueTrackBase *this)
{
  this->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable';
}

// File Line: 137
// RVA: 0x3020A0
__int64 __fastcall DialogueTrackBase::GetTag(DialogueTrackBase *this, int listId, char *name)
{
  __int64 v3; // rdi
  unsigned int v4; // ebx
  __int64 v5; // rdx
  EnumList<unsigned long> *v6; // r9
  __int64 v7; // r10
  EnumList<unsigned long> *v8; // r11
  char *v9; // r9
  char v10; // cl
  __int64 v11; // r9
  __int64 v12; // rdx
  __int64 v13; // rcx
  unsigned int *v14; // rax
  char *v15; // rdx
  char v16; // al

  v3 = (unsigned int)this->m_dialogueTagId[listId];
  v4 = this->m_dialogueTagUid[listId];
  if ( name )
  {
    v5 = 0i64;
    if ( (signed __int64)audioEnum.m_enumLists.size <= 0 )
    {
LABEL_9:
      v7 = 0i64;
      if ( (signed __int64)audioEnum.m_enumLists.size > 0 )
      {
        while ( 1 )
        {
          v8 = (signed int)audioEnum.m_enumLists.size <= 0 ? 0i64 : audioEnum.m_enumLists.p[v7];
          v11 = v8->m_enumName.size;
          v12 = 0i64;
          v13 = 0i64;
          if ( v11 > 0 )
            break;
LABEL_20:
          if ( ++v7 >= audioEnum.m_enumLists.size )
            return (unsigned int)v3;
        }
        v14 = v8->m_enumValue.p;
        while ( v4 != *v14 )
        {
          ++v13;
          v12 = (unsigned int)(v12 + 1);
          ++v14;
          if ( v13 >= v11 )
            goto LABEL_20;
        }
        v15 = v8->m_enumName.p[v12];
        do
        {
          v16 = *v15;
          ++name;
          ++v15;
          *(name - 1) = v16;
        }
        while ( v16 );
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = (signed int)audioEnum.m_enumLists.size <= 0 ? 0i64 : audioEnum.m_enumLists.p[v5];
        if ( (signed int)v3 < (signed int)v6->m_enumName.size && v4 == v6->m_uid.p[v3] )
          break;
        if ( ++v5 >= audioEnum.m_enumLists.size )
          goto LABEL_9;
      }
      v9 = v6->m_enumName.p[v3];
      do
      {
        v10 = *v9;
        ++name;
        ++v9;
        *(name - 1) = v10;
      }
      while ( v10 );
    }
  }
  return (unsigned int)v3;
}

// File Line: 185
// RVA: 0x14952D0
__int64 dynamic_initializer_for__DialogueTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DialogueTrack", 0xFFFFFFFF);
  DialogueTrack::sClassNameUID = result;
  return result;
}

// File Line: 202
// RVA: 0x2DF170
void __fastcall DialogueTrack::DialogueTrack(DialogueTrack *this)
{
  DialogueTrack *v1; // rbx
  unsigned int *v2; // rax
  signed __int64 v3; // rcx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DialogueTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DialogueTask>::`vftable';
  v1->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable';
  v1->m_playPercent = 100.0;
  v1->m_priority = 5;
  v2 = v1->m_dialogueTagUid;
  v3 = 3i64;
  do
  {
    *(v2 - 3) = 0;
    *v2 = 0;
    ++v2;
    --v3;
  }
  while ( v3 );
  v1->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrack::`vftable'{for `Track<DialogueTask>'};
  v1->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrack::`vftable'{for `DialogueTrackBase'};
}

// File Line: 206
// RVA: 0x2E3EC0
void __fastcall DialogueTrack::~DialogueTrack(DialogueTrack *this)
{
  DialogueTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrack::`vftable'{for `Track<DialogueTask>'};
  this->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrack::`vftable'{for `DialogueTrackBase'};
  this->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 219
// RVA: 0x14952F0
__int64 dynamic_initializer_for__DialogueTrackPOI::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DialogueTrackPOI", 0xFFFFFFFF);
  DialogueTrackPOI::sClassNameUID = result;
  return result;
}

// File Line: 234
// RVA: 0x2DF1F0
void __fastcall DialogueTrackPOI::DialogueTrackPOI(DialogueTrackPOI *this)
{
  DialogueTrackPOI *v1; // rbx
  unsigned int *v2; // rax
  signed __int64 v3; // rcx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DialogueTrackPOI::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DialogueTaskPOI>::`vftable';
  v1->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable';
  v1->m_playPercent = 100.0;
  v1->m_priority = 5;
  v2 = v1->m_dialogueTagUid;
  v3 = 3i64;
  do
  {
    *(v2 - 3) = 0;
    *v2 = 0;
    ++v2;
    --v3;
  }
  while ( v3 );
  v1->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackPOI::`vftable'{for `Track<DialogueTaskPOI>'};
  v1->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackPOI::`vftable'{for `DialogueTrackBase'};
}

// File Line: 239
// RVA: 0x2E3F50
void __fastcall DialogueTrackPOI::~DialogueTrackPOI(DialogueTrackPOI *this)
{
  DialogueTrackPOI *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackPOI::`vftable'{for `Track<DialogueTaskPOI>'};
  this->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackPOI::`vftable'{for `DialogueTrackBase'};
  this->vfptr = (DialogueTrackBaseVtbl *)&DialogueTrackBase::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 252
// RVA: 0x1495310
__int64 dynamic_initializer_for__DialogueTrackWeaponImpact::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DialogueTrackWeaponImpact", 0xFFFFFFFF);
  DialogueTrackWeaponImpact::sClassNameUID = result;
  return result;
}

// File Line: 265
// RVA: 0x2DF270
void __fastcall DialogueTrackWeaponImpact::DialogueTrackWeaponImpact(DialogueTrackWeaponImpact *this)
{
  DialogueTrackWeaponImpact *v1; // rbx
  unsigned int *v2; // rax
  signed __int64 v3; // rcx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DialogueTrackWeaponImpact::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DialogueTaskWeaponImpact>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackWeaponImpact::`vftable';
  v1->m_playPercent = 100.0;
  v1->m_priority = 5;
  v2 = v1->m_dialogueTagUid;
  v3 = 2i64;
  do
  {
    *(v2 - 2) = 0;
    *v2 = 0;
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 276
// RVA: 0x2E3FD0
void __fastcall DialogueTrackWeaponImpact::~DialogueTrackWeaponImpact(DialogueTrackWeaponImpact *this)
{
  DialogueTrackWeaponImpact *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DialogueTrackWeaponImpact::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 312
// RVA: 0x1494FF0
__int64 dynamic_initializer_for__ConversationTrackCreate::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackCreate", 0xFFFFFFFF);
  ConversationTrackCreate::sClassNameUID = result;
  return result;
}

// File Line: 319
// RVA: 0x2DE720
void __fastcall ConversationTrackCreate::ConversationTrackCreate(ConversationTrackCreate *this)
{
  ConversationTrackCreate *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ConversationTrackCreate::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ConversationTaskCreate>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ConversationTrackCreate::`vftable';
  v1->m_topic = 0;
}

// File Line: 332
// RVA: 0x1494FD0
__int64 dynamic_initializer_for__ConversationTrackCleanup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackCleanup", 0xFFFFFFFF);
  ConversationTrackCleanup::sClassNameUID = result;
  return result;
}

// File Line: 345
// RVA: 0x1495030
__int64 dynamic_initializer_for__ConversationTrackOperation::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackOperation", 0xFFFFFFFF);
  ConversationTrackOperation::sClassNameUID = result;
  return result;
}

// File Line: 359
// RVA: 0x1495010
__int64 dynamic_initializer_for__ConversationTrackInterrupt::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ConversationTrackInterrupt", 0xFFFFFFFF);
  ConversationTrackInterrupt::sClassNameUID = result;
  return result;
}

