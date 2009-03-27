/*****************************
 * Tracker Functions
 * ***************************/ 

TrackerServerInfo* tracker_get_connection();
int tracker_connect_server(TrackerServerInfo* pTrackerServer);
void tracker_disconnect_server(TrackerServerInfo* pTrackerServer);
void tracker_close_all_connections();
int tracker_list_groups(TrackerServerInfo* pTrackerServer, \
			FDFSGroupStat* group_stats, const int max_groups, \
			int* group_count);
int tracker_list_servers(TrackerServerInfo* pTrackerServer,\
			const char* szGroupName, \
			FDFSStrorageInfo* storage_infos, const int max_storages,\
			int* storage_count);
int tracker_query_storage_store(TrackerServerInfo* pTrackerServer,\
			TrackerServerInfo *pStorageServer);
int tracker_query_storage_fetch(TrackerServerInfo* pTrackerServer,\
			TrackerServerInfo* pStorageServer, \
			const char* group_name, const char* filename);

/***************************** 
 * Storage Functions
 ******************************/

int storage_upload_by_filename(TrackerServerInfo* pTrackerServer,\
			TrackerServerInfo* pStorageServer, \
			const char* local_filename, \
			const FDFSMetaData* meta_list, \
			const int meta_count, \
			char* group_name, \
			char* remote_filename);
		
int storage_upload_by_filebuff(TrackerServerInfo *pTrackerServer, \
			TrackerServerInfo *pStorageServer, \
			const char *file_buff, const int file_size, \
			const FDFSMetaData *meta_list, \
			const int meta_count, \
			char *group_name, \
			char *remote_filename);

int storage_delete_file(TrackerServerInfo *pTrackerServer, \
			TrackerServerInfo *pStorageServer, \
			const char *group_name, const char *filename);

int storage_set_metadata(TrackerServerInfo *pTrackerServer, \
			TrackerServerInfo *pStorageServer, \
			const char *group_name, const char *filename, \
			FDFSMetaData *meta_list, const int meta_count, \
			const char op_flag);

int storage_download_file(TrackerServerInfo *pTrackerServer, \
			TrackerServerInfo *pStorageServer, \
			const char *group_name, const char *filename, \
			char **file_buff, int *file_size);

int storage_get_metadata(TrackerServerInfo *pTrackerServer, \
			TrackerServerInfo *pStorageServer,  \
			const char *group_name, const char *filename, \
			FDFSMetaData **meta_list, \
			int *meta_count);
