#pragma once
/*
Player class

�E�J�[�h
�E�`�b�v
�E���O
�E�X�[�g
�Eorder;//�����Ԗڂ�

CPU class
�E�J�[�h
�E�`�b�v
�E���O
�E�X�[�g 

controller class
�E���͏���
�E�e��T�u�E�B���h�E�I���Ăяo��(�N���b�Nor�L�[)
�E


����Ǘ�����N���X

GameMgr

�E�|�b�h
�E�Q�[�������ǂ̃t�F�C�Y�Ȃ̂�
�E�ǂ̃v���C���[���ǂ̃J�[�h���o���Ă��āA�����`�b�v��q���Ă���̂�
�E�܂����܂łǂ̃v���C���[���ǂ̃J�[�h���o���Ă����̂��̗���
�E�Q�[���̃��[�����Ǘ�����N���X(�J�[�h�̋����`�b�v�̕␳)
�E�w�i�摜
�E�D�悷��v���C���[�̐ݒ�

�����̊Ǘ��A�\��


���҂��������̑I�����҂��������̑I�������聨����





*/

/**
 *
 *
 *
 */

/**
 * \brief Chunk�Ƀf�[�^��ǉ�����
 * \warning �����Ă���f�[�^�͖���`
 * \return �쐬����Entity
 */
//Entity createEntity();

/**
 * \brief Entity�𑼂̃`�����N�Ɉړ�������
 * \param entity �ړ�������Entity
 * \param other �ړ���Chunk
 */
//void moveEntity( Entity& entity, Chunk& other );

/**
 * \brief �f�[�^���擾����
 * \tparam T Archetype�ɐݒ肳��Ă��邢���ꂩ�̌^
 * \return T�̔z��
 */
/*
template<class T>
[[nodiscard]] ComponentArray<T> getComponentArray()
{
	using TType = std::remove_const_t<std::remove_reference_t<T>>;
	auto offset = mArchetype.getOffset<TType>() * mCapacity;
	return ComponentArray<T>(reinterpret_cast<TType*>(mpBegin.get() + offset), mSize);
}*/


/**
 * \brief
 * Chunk���̃f�[�^�\����\��
 * �^�̏��Ԃ��֌W�Ȃ�����
 * Archetype::create<Position,Rotation,Scale>() == Archetype::create<Rotation,Scale,Position>()
 */
//struct Archetype


/**
 * \brief IComponentData���p�������^�܂ł̃������T�C�Y���擾
 * \details Archetype�Ɋ܂܂�Ȃ��^�̏ꍇgetArchetypeSize()�Ɠ����l��Ԃ�
 * \tparam Type IComponentData
 * \return Index�܂ł̃o�C�g��
 */

/**
 * \brief ���݂�Size��Capacity��؂�l�߂�
 */
/**
 * 
 */
//void fit();