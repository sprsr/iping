typedef struct frame_op { 
    int typeL3;
    int typeL4;
}frame_op;
frame_op* init_frame_op();
void genframe(frame_op* options);
