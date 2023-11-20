// File Line: 32
// RVA: 0xAAD780
signed __int64 __fastcall AkMusicBank::LoadBankItem(AkBank::AKBKSubHircSection *in_rSection, CAkUsageSlot *in_pUsageSlot, unsigned int in_dwBankID)
{
  CAkUsageSlot *v3; // rdi
  AkBank::AKBKSubHircSection *v4; // rbx
  CAkAudioLibIndex *v5; // rax
  signed __int64 result; // rax
  CAkAudioLibIndex *v7; // rax
  CAkAudioLibIndex *v8; // rax

  v3 = in_pUsageSlot;
  v4 = in_rSection;
  switch ( in_rSection->eHircType )
  {
    case 0xA:
      v8 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
      result = CAkBankMgr::StdBankRead<CAkMusicSegment,CAkParameterNodeBase>(
                 g_pBankManager,
                 v4,
                 v3,
                 &v8->m_idxAudioNode);
      break;
    case 0xB:
      result = CAkBankMgr::ReadSourceParent<CAkMusicTrack>(g_pBankManager, in_rSection, in_pUsageSlot, in_dwBankID);
      break;
    case 0xC:
      v7 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
      result = CAkBankMgr::StdBankRead<CAkMusicSwitchCntr,CAkParameterNodeBase>(
                 g_pBankManager,
                 v4,
                 v3,
                 &v7->m_idxAudioNode);
      break;
    case 0xD:
      v5 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
      result = CAkBankMgr::StdBankRead<CAkMusicRanSeqCntr,CAkParameterNodeBase>(
                 g_pBankManager,
                 v4,
                 v3,
                 &v5->m_idxAudioNode);
      break;
    default:
      result = 3i64;
      break;
  }
  return result;
}

