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
//�g�����v����
/*
1���̃T�C�Y
128*192px

��(����X�[�g)�̕�
8*192px

�c(���ꐔ��)�̕�
128*8px

1���̃J�[�h�ɂ͎����4px�̕�������


Tx=128;
Ty=192;
Tp=8;

enum s;
�X�y�[�h	0
�n�[�g		1
�_�C�A		2
�N���[�o�[	3

�X�y�[�h	(Tp*0+Tx*0,Tp*0+Ty*0)=(0,  0)	(Tp*1+Tx*1,Tp*0+Ty*0)=(136,	 0)
�n�[�g		(Tp*0+Tx*0,Tp*1+Ty*1)=(0,200)	(Tp*1+Tx*1,Tp*1+Ty*1)=(136,200)
�_�C�A		(Tp*0+Tx*0,Tp*2+Ty*2)=(0,400)	(Tp*1+Tx*1,Tp*2+Ty*2)=(136,400)
�N���[�o�[	(Tp*0+Tx*0,Tp*3+Ty*3)=(0,600)	(Tp*1+Tx*1,Tp*3+Ty*3)=(136,600)


�X�y�[�h	((Tp+Tx)*0,(Tp+Ty)*0)=(0,  0)	((Tp+Tx)*1,(Tp+Ty)*0)=(136,	 0)
�n�[�g		((Tp+Tx)*0,(Tp+Ty)*1)=(0,200)	((Tp+Tx)*1,(Tp+Ty)*1)=(136,200)
�_�C�A		((Tp+Tx)*0,(Tp+Ty)*2)=(0,400)	((Tp+Tx)*1,(Tp+Ty)*2)=(136,400)
�N���[�o�[	((Tp+Tx)*0,(Tp+Ty)*3)=(0,600)	((Tp+Tx)*1,(Tp+Ty)*3)=(136,600)


�W���[�J�[	((Tp+Tx)*13,(Tp+Ty)*0)=(1768,  0)
��			((Tp+Tx)*13,(Tp+Ty)*1)=(1768,200)
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