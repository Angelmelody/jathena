#ifndef _NULLPO_H_
#define _NULLPO_H_

#if __STDC_VERSION__ < 199901L
# if __GNUC__ >= 2
#  define __func__ __FUNCTION__
# else
#  define __func__ ""
# endif
#endif

#define NLP_MARK __FILE__, __LINE__, __func__

/*----------------------------------------------------------------------------
 * Macros
 *----------------------------------------------------------------------------
 */
/*======================================
 * Null�`�F�b�N �y�� ���o�͌� return
 *--------------------------------------
 * nullpo_ret(t)
 *   �߂�l 0�Œ�
 * [����]
 *  t       �`�F�b�N�Ώ�
 *--------------------------------------
 * nullpo_retr(ret, t)
 *   �߂�l�w��
 * [����]
 *  ret     return(ret);
 *  t       �`�F�b�N�Ώ�
 *--------------------------------------
 * nullpo_retv(t)
 *   �߂�l �Ȃ�
 * [����]
 *  t       �`�F�b�N�Ώ�
 *--------------------------------------
 * nullpo_ret_f(t, fmt, ...)
 *   �ڍ׏��o�͗p
 *   �߂�l 0
 * [����]
 *  t       �`�F�b�N�Ώ�
 *  fmt ... vprintf�ɓn�����
 *    ���l��֌W�ϐ��̏����o���Ȃǂ�
 *--------------------------------------
 * nullpo_retr_f(ret, t, fmt, ...)
 *   �ڍ׏��o�͗p
 *   �߂�l�w��
 * [����]
 *  ret     return(ret);
 *  t       �`�F�b�N�Ώ�
 *  fmt ... vprintf�ɓn�����
 *    ���l��֌W�ϐ��̏����o���Ȃǂ�
 *--------------------------------------
 */
 
#define nullpo_retr(ret, t) \
	if (nullpo_chk(NLP_MARK, (void *)(t))) {return(ret);}

#define nullpo_retv(t) \
	if (nullpo_chk(NLP_MARK, (void *)(t))) {return;}

#define nullpo_ret(t) \
	nullpo_retr(0, (t))


// �ψ����}�N���Ɋւ�������R���p�C��
#if __STDC_VERSION__ >= 199901L
/* C99�ɑΉ� */
#define nullpo_retr_f(ret, t, fmt, ...) \
	if (nullpo_chk_f(NLP_MARK, (void *)(t), (fmt), __VA_ARGS__)) {return(ret);}

#define nullpo_ret_f(t, fmt, ...) \
	nullpo_retr_f(0, (t), (fmt), __VA_ARGS__)

#elif __GNUC__ >= 2
/* �Â�GCC�p */
#define nullpo_retr_f(ret, t, fmt, args...) \
	if (nullpo_chk_f(NLP_MARK, (void *)(t), (fmt), ## args)) {return(ret);}

#define nullpo_ret_f(t, fmt, args...) \
	nullpo_retr_f(0, (t), (fmt), ## args)

#else

/* ���̑��̏ꍇ�E�E�E orz */

#endif

/*----------------------------------------------------------------------------
 * Functions
 *----------------------------------------------------------------------------
 */
/*======================================
 * nullpo_chk
 *   Null�`�F�b�N �y�� ���o��
 * [����]
 *  file    __FILE__
 *  line    __LINE__
 *  func    __func__ (�֐���)
 *    �����ɂ� NLP_MARK ���g���Ƃ悢
 *  target  �`�F�b�N�Ώ�
 * [�Ԃ�l]
 *  0 OK
 *  1 NULL
 *--------------------------------------
 */
int nullpo_chk(const char *file, int line, const char *func, const void *target);


/*======================================
 * nullpo_chk_f
 *   Null�`�F�b�N �y�� �ڍׂȏ��o��
 * [����]
 *  file    __FILE__
 *  line    __LINE__
 *  func    __func__ (�֐���)
 *    �����ɂ� NLP_MARK ���g���Ƃ悢
 *  target  �`�F�b�N�Ώ�
 *  fmt ... vprintf�ɓn�����
 *    ���l��֌W�ϐ��̏����o���Ȃǂ�
 * [�Ԃ�l]
 *  0 OK
 *  1 NULL
 *--------------------------------------
 */
int nullpo_chk_f(const char *file, int line, const char *func, const void *target,
                 const char *fmt, ...)
                 __attribute__((format(printf,5,6)));


/*======================================
 * nullpo_info
 *   nullpo���o��
 * [����]
 *  file    __FILE__
 *  line    __LINE__
 *  func    __func__ (�֐���)
 *    �����ɂ� NLP_MARK ���g���Ƃ悢
 *--------------------------------------
 */
void nullpo_info(const char *file, int line, const char *func);


/*======================================
 * nullpo_info_f
 *   nullpo�ڍ׏��o��
 * [����]
 *  file    __FILE__
 *  line    __LINE__
 *  func    __func__ (�֐���)
 *    �����ɂ� NLP_MARK ���g���Ƃ悢
 *  fmt ... vprintf�ɓn�����
 *    ���l��֌W�ϐ��̏����o���Ȃǂ�
 *--------------------------------------
 */
void nullpo_info_f(const char *file, int line, const char *func, 
                   const char *fmt, ...)
                   __attribute__((format(printf,4,5)));


#endif
