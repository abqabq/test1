pthread_mutex_t count_mutex;
pthread_mutex_t write_mutex;
int read_count = 0;

void read_lock() {
  pthread_mutex_lock(count_mutex);
  read_count++;
  if (read_count == 1) {
    pthread_mutex_lock(write_mutex);
  }
  pthread_mutex_unlock(count_mutex);  
}

void read_unlock() {
  pthread_mutex_lock(count_mutex);
  read_count--;
  if (read_count == 0) {
    pthread_mutex_unlock(write_mutex);
  }
  pthread_mutex_unlock(count_mutex);
}

void write_lock() {
  pthread_mutex_lock(write_mutex);
}

void write_unlock() {
  pthread_mutex_unlock(write_mutex);
}


int main(void) {
    if (pthread_mutex_init(&count_mutex, NULL) != 0)
    {
        printf("\n count_mutex init failed\n");
        return 1;
    }
    
    if (pthread_mutex_init(&write_mutex, NULL) != 0)
    {
        printf("\n write_mutex init failed\n");
        return 1;
    }
    
    pthread_mutex_unlock(&count_mutex);
    pthread_mutex_unlock(&write_mutex);
}

